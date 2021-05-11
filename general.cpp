// put on Release + x64 !!

// d3d + d2d v1 maybe?

#include <string>
#include <vector>
#include <algorithm>
#define STB_IMAGE_IMPLEMENTATION
#include "imgui/stb_image.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui/imgui_internal.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include "imgui/imgui_xorstr.h"
#include "background_texture.h"
#include "Draw.h"

struct d3d
{
    ID3D11Device* pDevice = NULL;
    ID3D11DeviceContext* pDeviceContext = NULL;
    IDXGISwapChain* pSwapChain = NULL;
    ID3D11RenderTargetView* pRenderTarget = NULL;
    bool ios;
};
d3d d3dinit;
void CreateRenderTarget()
{
    DXGI_SWAP_CHAIN_DESC sd;
    d3dinit.pSwapChain->GetDesc(&sd);
    ID3D11Texture2D* pBackBuffer;
    D3D11_RENDER_TARGET_VIEW_DESC render_target_view_desc;
    ZeroMemory(&render_target_view_desc, sizeof(render_target_view_desc));
    render_target_view_desc.Format = sd.BufferDesc.Format;
    render_target_view_desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
    d3dinit.pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
    d3dinit.pDevice->CreateRenderTargetView(pBackBuffer, &render_target_view_desc, &d3dinit.pRenderTarget);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (d3dinit.pRenderTarget) { d3dinit.pRenderTarget->Release(); d3dinit.pRenderTarget = NULL; }
}

HRESULT CreateDeviceD3D(HWND hWnd)
{
    DXGI_SWAP_CHAIN_DESC sd;
    {
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = 2;
        sd.BufferDesc.Width = 0;
        sd.BufferDesc.Height = 0;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = hWnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    }

    UINT createDeviceFlags = 0;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &d3dinit.pSwapChain, &d3dinit.pDevice, &featureLevel, &d3dinit.pDeviceContext) != S_OK)
        return E_FAIL;
    CreateRenderTarget();
    return S_OK;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (d3dinit.pSwapChain) { d3dinit.pSwapChain->Release(); d3dinit.pSwapChain = NULL; }
    if (d3dinit.pDeviceContext) { d3dinit.pDeviceContext->Release(); d3dinit.pDeviceContext = NULL; }
    if (d3dinit.pDevice) { d3dinit.pDevice->Release(); d3dinit.pDevice = NULL; }
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WindowProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (d3dinit.pDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            ImGui_ImplDX11_InvalidateDeviceObjects();
            CleanupRenderTarget();
            d3dinit.pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
            ImGui_ImplDX11_CreateDeviceObjects();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

int main(int, char**)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WindowProcess, 0L, 0L, GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL, _T("Luxury Menu Examples"), NULL };
    RegisterClassEx(&wc);
    HWND hwnd = CreateWindow(_T("Luxury Menu Examples"), _T("Menu Examples"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);
    if (CreateDeviceD3D(hwnd) < 0)
    {
        CleanupDeviceD3D();
        UnregisterClass(_T("Luxury Menu Examples"), wc.hInstance);
        return 1;
    }
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);
    ImGui_ImplDX11_Init(hwnd, d3dinit.pDevice, d3dinit.pDeviceContext);

    if (!d3dinit.ios)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DeltaTime = 1.0f / 60.0f;
        io.IniFilename = NULL;

        if (g_font.Viper)
        {
            io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 15);
        }
        if (g_font.ElectricPlug)
        {
            io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 18);
        }
        if (g_font.Tahoma)
        {
            io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 15);
        }
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 17);
    }

    initrainbow::load_rainbow();
    ImVec4 BackgroundColor = ImColor(100, 130, 150);
    
    MSG Message;
    ZeroMemory(&Message, sizeof(Message));
    while (Message.message != WM_QUIT)
    {
        if (PeekMessage(&Message, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
            continue;
        }
        ImGui_ImplDX11_NewFrame();
        d3dinit.pDeviceContext->OMSetRenderTargets(1, &d3dinit.pRenderTarget, NULL);
        d3dinit.pDeviceContext->ClearRenderTargetView(d3dinit.pRenderTarget, (float*)&BackgroundColor);

        // Render Menus here | fixed debug on menus.
        g_config.Simple();
      //  g_config.Simple2();
       // g_config.ElectricPlug();
        //tutorial();
      //  g_config.Viper();
        ImGui::Render();
        d3dinit.pSwapChain->Present(1, 0);
    }

    ImGui_ImplDX11_Shutdown();
    CleanupDeviceD3D();
    UnregisterClass(_T("Luxury Menus Examples"), wc.hInstance);

    return 0;
}
