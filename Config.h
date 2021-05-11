
struct rainbow
{
	float main_red_ = 1.;
	float main_green_ = 0;
	float main_blue_ = 0;
	float main_color_random = 0.0;
	float main_speed = -5.0;
};
rainbow r_c;

namespace initrainbow
{
	void load_rainbow()
	{
		static float c_colr[3];
		struct tick_
		{
			DWORD tick_count = 0;
			DWORD tick_count2 = 0;
		};
		tick_ t_c_;
		ImGui::ColorConvertRGBtoHSV(r_c.main_red_, r_c.main_green_, r_c.main_blue_, c_colr[0], c_colr[1], c_colr[2]);
		if (GetTickCount() - t_c_.tick_count >= 1)
		{
			if (t_c_.tick_count != t_c_.tick_count)
			{
				c_colr[0] += 0.001f * r_c.main_speed;
				t_c_.tick_count2 = t_c_.tick_count;
			}
			t_c_.tick_count = GetTickCount();
		}
		if (c_colr[0] < 0.0f) c_colr[0] += 1.0f;
		ImGui::ColorConvertHSVtoRGB(c_colr[0], c_colr[1], c_colr[2], r_c.main_red_, r_c.main_green_, r_c.main_blue_);
	}
}

struct fontinit
{
	ImFont* Viper;
	ImFont* ElectricPlug;
	ImFont* Tahoma;
};
fontinit g_font;

struct Config
{
	// Fortnite Menus
	void ElectricPlug();        // Doesnt Include Symbols / Arrow Key System
	void Viper();               // No Arrow Key System
	void Desync();              // Doesnt include particles
	void Tutorial(); 
	void CSGOCustom();
	void MillionWare();
	void CheatLoverz();
	void Simple();
	void Simple2();
	void Applecheats();
	void MakFN();

};
Config g_config;

bool ColorBarEx(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;

	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrentLineTextBaseOffset)
		pos.y += window->DC.CurrentLineTextBaseOffset - style.FramePadding.y;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, pos + size);

	ImGui::ItemSize(bb, style.FramePadding.y);

	if (!ImGui::ItemAdd(bb, id))
		return false;

	if (window->DC.ItemFlags & ImGuiItemFlags_ButtonRepeat)
		flags |= ImGuiButtonFlags_Repeat;

	// Render
	auto black = ImGui::GetColorU32(ImVec4(0.0, 0.0, 0.0, 0.43));
	ImVec2 p = ImGui::GetCursorScreenPos();

	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x, p.y - 6), ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 4), ImColor(12, 12, 12), ImColor(12, 12, 12), ImColor(12, 12, 12), ImColor(12, 12, 12));
	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 6), ImVec2(p.x + ImGui::GetWindowWidth(), p.y - 4), ImColor(12, 12, 12), ImColor(12, 12, 12), ImColor(12, 12, 12), ImColor(12, 12, 12));

	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x + 1, p.y - 5), ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 3), ImColor(55, 177, 218), ImColor(201, 84, 192), ImColor(201, 84, 192), ImColor(55, 177, 218));
	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 5), ImVec2(p.x + ImGui::GetWindowWidth() - 1, p.y - 3), ImColor(201, 84, 192), ImColor(204, 227, 54), ImColor(204, 227, 54), ImColor(201, 84, 192));

	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x + 1, p.y - 4), ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 2), black, black, black, black);
	window->DrawList->AddRectFilledMultiColor(ImVec2(p.x + ImGui::GetWindowWidth() / 2, p.y - 4), ImVec2(p.x + ImGui::GetWindowWidth() - 1, p.y - 2), black, black, black, black);

	return false;
}
bool ColorBar(const char* label, const ImVec2& size_arg)
{
	return ColorBarEx(label, size_arg, 0);
}
namespace csgo
{
	struct rainbowbar
	{
		void cs_go_rainbow()
		{
			ColorBar("", ImVec2(200.f, 2.f));
		}
		void cs_go_rainbow_animated()
		{
		}
	};
	rainbowbar r_csgo_;
	rainbowbar* r_csgo = new rainbowbar;

}
namespace Draw
{
	typedef struct
	{
		DWORD R;
		DWORD G;
		DWORD B;
		DWORD A;
	}RGBA;

	class RBGAColr
	{
	public:
		RGBA red = { 255,0,0,255 };
		RGBA Magenta = { 255,0,255,255 };
		RGBA yellow = { 255,255,0,255 };
		RGBA grayblue = { 128,128,255,255 };
		RGBA green = { 128,224,0,255 };
		RGBA darkgreen = { 0,224,128,255 };
		RGBA brown = { 192,96,0,255 };
		RGBA pink = { 255,168,255,255 };
		RGBA DarkYellow = { 216,216,0,255 };
		RGBA SilverWhite = { 236,236,236,255 };
		RGBA purple = { 144,0,255,255 };
		RGBA Navy = { 88,48,224,255 };
		RGBA skyblue = { 0,136,255,255 };
		RGBA graygreen = { 128,160,128,255 };
		RGBA blue = { 0,96,192,255 };
		RGBA orange = { 255,128,0,255 };
		RGBA peachred = { 255,80,128,255 };
		RGBA reds = { 255,128,192,255 };
		RGBA darkgray = { 96,96,96,255 };
		RGBA Navys = { 0,0,128,255 };
		RGBA darkgreens = { 0,128,0,255 };
		RGBA darkblue = { 0,128,128,255 };
		RGBA redbrown = { 128,0,0,255 };
		RGBA purplered = { 128,0,128,255 };
		RGBA greens = { 0,255,0,255 };
		RGBA envy = { 0,255,255,255 };
		RGBA black = { 0,0,0,255 };
		RGBA gray = { 128,128,128,255 };
		RGBA white = { 255,255,255,255 };
		RGBA blues = { 30,144,255,255 };
		RGBA lightblue = { 135,206,250,160 };
		RGBA Scarlet = { 220, 20, 60, 160 };
		RGBA white_ = { 255,255,255,200 };
		RGBA gray_ = { 128,128,128,200 };
		RGBA black_ = { 0,0,0,200 };
		RGBA red_ = { 255,0,0,200 };
		RGBA Magenta_ = { 255,0,255,200 };
		RGBA yellow_ = { 255,255,0,200 };
		RGBA grayblue_ = { 128,128,255,200 };
		RGBA green_ = { 128,224,0,200 };
		RGBA darkgreen_ = { 0,224,128,200 };
		RGBA brown_ = { 192,96,0,200 };
		RGBA pink_ = { 255,168,255,200 };
		RGBA darkyellow_ = { 216,216,0,200 };
		RGBA silverwhite_ = { 236,236,236,200 };
		RGBA purple_ = { 144,0,255,200 };
		RGBA Blue_ = { 88,48,224,200 };
		RGBA skyblue_ = { 0,136,255,200 };
		RGBA graygreen_ = { 128,160,128,200 };
		RGBA blue_ = { 0,96,192,200 };
		RGBA orange_ = { 255,128,0,200 };
		RGBA pinks_ = { 255,80,128,200 };
		RGBA Fuhong_ = { 255,128,192,200 };
		RGBA darkgray_ = { 96,96,96,200 };
		RGBA Navy_ = { 0,0,128,200 };
		RGBA darkgreens_ = { 0,128,0,200 };
		RGBA darkblue_ = { 0,128,128,200 };
		RGBA redbrown_ = { 128,0,0,200 };
		RGBA purplered_ = { 128,0,128,200 };
		RGBA greens_ = { 0,255,0,200 };
		RGBA envy_ = { 0,255,255,200 };
		RGBA glassblack = { 0, 0, 0, 160 };
		RGBA GlassBlue = { 65,105,225,80 };
		RGBA glassyellow = { 255,255,0,160 };
		RGBA glass = { 200,200,200,60 };
		RGBA Plum = { 221,160,221,160 };
		RGBA neongreen = { 0, 255, 229,0 };

	};
	RBGAColr Color;

	std::string string_To_UTF8(const std::string& str)
	{
		int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
		wchar_t* pwBuf = new wchar_t[nwLen + 1];
		ZeroMemory(pwBuf, nwLen * 2 + 2);
		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
		int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
		char* pBuf = new char[nLen + 1];
		ZeroMemory(pBuf, nLen + 1);
		::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
		std::string retStr(pBuf);
		delete[]pwBuf;
		delete[]pBuf;
		pwBuf = NULL;
		pBuf = NULL;
		return retStr;
	}
	// Drawings for custom menus + Toggle Button's / Checkboxes ETC
	void RegularRGBText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void ShadowRGBText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void OutlinedRBGText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 30 / 30.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 30 / 30.0)), utf_8_2.c_str());
		//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void RegularText(int x, int y, RGBA* color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	}
	void NeonRBGText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y - 1), ImColor(64, 255, 0), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 1), ImColor(64, 255, 0), utf_8_2.c_str());
		//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	}
	void BackgroundRBGOutline(int x, int y, int w, int h, ImColor color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0, thickness);
	}
	void BackgroundOutline(int x, int y, int w, int h, RGBA* color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
	}
	void TitleBar(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
	}
	void TitleBarGraident(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
	}
	void BackgroundLowOpacity(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.20f)), 0);
	}

	void BackgroundLowRounded(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.20f)), 6);
	}

	void BackgroundRBGGradient(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void BackgroundFilledRBG(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void SelectedFilled(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.40f)), 0, 0);
	}

	void BackgroundFilled(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0);
	}

	void BackgroundFilledRound(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 6);
	}

	void BackgroundGradient(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0, 0);
	}

	// checkbox's / buttons / toggle buttons / sliders

	struct color {
		float a, r, g, b;
		color() = default;
		color(float r, float g, float b, float a = 255) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
		color(uint32_t color) {
			this->a = (color >> 24) & 0xff;
			this->r = (color >> 16) & 0xff;
			this->g = (color >> 8) & 0xff;
			this->b = (color & 0xff);
		}
		color from_uint(uint32_t uint) {
			return color(uint);
		}

		static color black(float a = 255) { return { 0, 0, 0, a }; }
		static color white(float a = 255) { return { 255, 255, 255, a }; }
		static color red(float   a = 255) { return { 255, 0, 0, a }; }
		static color green(float a = 255) { return { 0, 255, 0, a }; }
		static color blue(float  a = 255) { return { 0, 0, 255, a }; }
	};

	void ModernToggle(const char* str_id, bool* v)
	{
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight();
		float width = height * 1.55f;
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
		else
			col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.10f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.f, ImColor(255, 255, 255, 255));

	}

	bool Checkbox(const char* label, bool* v)
	{
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		if (window->SkipItems)
			return false;
		ImGuiContext& g = *GImGui;
		const ImGuiStyle& style = ImGuiStyle::ImGuiStyle();
		const float square_sz = ImGui::GetFrameHeight();
		const ImGuiID id = window->GetID(label);
		const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
		const ImVec2 pading = ImVec2(2, 2);
		const ImRect check_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(label_size.y + style.FramePadding.x * 6, label_size.y + style.FramePadding.y / 2));
		ImGui::ItemSize(check_bb, style.FramePadding.y);
		ImRect total_bb = check_bb;
		if (label_size.x > 0)
			ImGui::SameLine(0, style.ItemInnerSpacing.x);
		const ImRect text_bb(window->DC.CursorPos + ImVec2(0, style.FramePadding.y), window->DC.CursorPos + ImVec2(0, style.FramePadding.y) + label_size);
		if (label_size.x > 0)
		{
			ImGui::ItemSize(ImVec2(text_bb.GetWidth(), check_bb.GetHeight()), style.FramePadding.y);
			total_bb = ImRect(ImMin(check_bb.Min, text_bb.Min), ImMax(check_bb.Max, text_bb.Max));
		}
		if (!ImGui::ItemAdd(total_bb, id))
			return false;
		bool hovered, held;
		bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
		if (pressed)
			*v = !(*v);
		const float check_sz = ImMin(check_bb.GetWidth(), check_bb.GetHeight());
		const float check_sz2 = check_sz / 2;
		const float pad = ImMax(1.0f, (float)(int)(check_sz / 4.f));
		//window->DrawList->AddRectFilled(check_bb.Min+ImVec2(pad,pad), check_bb.Max-ImVec2(pad,pad), GetColorU32(ImGuiCol_CheckMark), style.FrameRounding);

		if (*v)
		{
			//window->DrawList->AddRectFilled(ImVec2(check_bb.Min.x + (check_bb.Max.x - check_bb.Min.x) / 2, check_bb.Min.y), check_bb.Max, GetColorU32(ImVec4(0.34f, 1.0f, 0.54f, 1.0f)), 0);
			//window->DrawList->AddRectFilled(ImVec2(check_bb.Min.x + (check_bb.Max.x - check_bb.Min.x) / 2, check_bb.Min.y), check_bb.Max, GetColorU32(ImVec4(0.34f, 1.0f, 0.54f, 1.0f)), 0);
			window->DrawList->AddRectFilled(ImVec2(check_bb.Min.x + 10, check_bb.Min.y + 5), ImVec2(check_bb.Min.x + 20, check_bb.Min.y + 15), ImColor(255, 0, 245));
			window->DrawList->AddRect(ImVec2(check_bb.Min.x + 10, check_bb.Min.y + 5), ImVec2(check_bb.Min.x + 20, check_bb.Min.y + 15), ImColor(47, 5, 45));
		}
		else
		{
			window->DrawList->AddRectFilled(ImVec2(check_bb.Min.x + 10, check_bb.Min.y + 5), ImVec2(check_bb.Min.x + 20, check_bb.Min.y + 15), ImColor(20, 20, 20));
			window->DrawList->AddRect(ImVec2(check_bb.Min.x + 10, check_bb.Min.y + 5), ImVec2(check_bb.Min.x + 20, check_bb.Min.y + 15), ImColor(5, 5, 5));
		}

		if (label_size.x > 0.0f)
			ImGui::RenderText(ImVec2(check_bb.Min.x + 27, check_bb.Min.y + 2), label);
		return pressed;
	}


	struct colors
	{
		struct red_type
		{
			ImColor main_lightred = { 255, 0, 0 };
			ImColor main_darkred = { 105, 0, 14 };
			ImColor main_velvetred = { 184, 46, 64 };
			ImColor main_cardinalred = { 189, 32, 53 };
			ImColor main_red = { 219, 9, 37 };
		};
		red_type rt_;
		struct grey_type
		{
			ImColor main_grey = { 92, 92, 91 };
			ImColor main_light_grey = { 161, 161, 161 };
			ImColor main_dark_grey = { 44, 45, 46 };
		};
		grey_type gt_;
		struct blue_type
		{
			ImColor main_purple_blue = { 81, 0, 255 };
			ImColor main_blue = { 28, 70, 255 };
		};
		blue_type bt_;
		ImColor main_rainbow = { r_c.main_red_, r_c.main_green_, r_c.main_blue_ };
		struct green_type
		{
			ImColor main_limegreen = { 81, 255, 0 };
			ImColor main_darkgreen = { 2, 133, 0 };
			ImColor main_lightgreen = { 13, 214, 26 };
			ImColor main_yellowgreen = { 145, 255, 0 };
		};
		green_type grt_;
	};
	colors colortype;
	colors ct;
	colors* color_m = new colors;
	colors* col = new colors;

	// how to use.
	// Draw::color_m->rt_.main_red | Draw::col->rt_.main_red | Draw::ct.rt_.main_red | Draw::colortype.rt_.main_red

	namespace easy_colr
	{
		ImColor main_lightred = { 255, 0, 0 };
		ImColor main_darkred = { 105, 0, 14 };
		ImColor main_velvetred = { 184, 46, 64 };
		ImColor main_cardinalred = { 189, 32, 53 };
		ImColor main_red = { 219, 9, 37 };
		ImColor main_grey = { 92, 92, 91 };
		ImColor main_light_grey = { 161, 161, 161 };
		ImColor main_dark_grey = { 44, 45, 46 };
		ImColor main_purple_blue = { 81, 0, 255 };
		ImColor main_blue = { 28, 70, 255 };
		ImColor main_rainbow = { r_c.main_red_, r_c.main_green_, r_c.main_blue_ };
	}

	static ImVec2 padding{ 5, 10 }; 
	static ImVec2 real_padding{ 12, 17 }; 
	static int last_widget = -1;

	static color to_color(ImVec4 in)
	{
		return color(in.x * 255, in.y * 255, in.z * 255, in.w * 255);
	}

	static color to_color(float* in)
	{
		return color(in[0], in[1], in[2], in[3]);
	}

	static ImVec4 to_vec(color in)
	{
		return ImVec4(in.r / 255, in.g / 255, in.b / 255, in.a / 255);
	}

	static void to_float(color in, float* out)
	{
		out[0] = in.r;
		out[1] = in.g;
		out[2] = in.b;
		out[3] = in.a;
	}

	static void apply_padding(ImVec2 pad)
	{
		pad.x += ImGui::GetCursorPosX();
		pad.y += ImGui::GetCursorPosY();
		ImGui::SetCursorPos(pad);
	}

	static void change_pos(ImVec2 pos) // resets to top of menu
	{
		ImGui::SetCursorPos(pos);
	}

	static void push_text(ImFont* font, std::string text, color clr = {}, ImVec2 pos = {})
	{
		if (pos.x != 0 && pos.y != 0)
		{
			ImGui::SetCursorPosY(pos.y); // center vertically
			ImGui::SetCursorPosX(pos.x); // positon left
		}

		if (clr.r && clr.g && clr.b)
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(clr.r / 255, clr.g / 255, clr.b / 255, 1));

		ImGui::PushFont(font);
		ImGui::Text(text.c_str());
		ImGui::PopFont();

		if (clr.r && clr.g && clr.b)
			ImGui::PopStyleColor();
		last_widget = 0;
	}

	static int page_number = 1;
	static std::vector<bool> toggles = { false, true, false, false, false };
	static void push_button_tab(ImFont* font, std::string text, bool transpearent, ImVec2 pos = {}, ImVec2 size = {}, color clr = {}, color active_clr = {}, int page = -1)
	{
		if (pos.x != 0 && pos.y != 0)
		{
			ImGui::SetCursorPosY(pos.y); // center vertically
			ImGui::SetCursorPosX(pos.x); // positon left
		}

		if (page >= 0 && toggles[page])
			ImGui::PushStyleColor(ImGuiCol_Text, to_vec(active_clr));
		else if (clr.r && clr.g && clr.b)
			ImGui::PushStyleColor(ImGuiCol_Text, to_vec(clr));

		if (transpearent)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
		}

		ImGui::PushFont(font);
		auto temp = ImGui::Button(text.c_str(), size);
		ImGui::PopFont();

		if (temp)
		{
			toggles = { false, false, false, false, false };
			toggles[page] = 1 - toggles[page];
			page_number = page;
		}

		if (transpearent)
			ImGui::PopStyleColor(4);

		if ((clr.r && clr.g && clr.b) || toggles[page])
			ImGui::PopStyleColor();
		last_widget = 1;
	}
	ImFont* InVisible;

	static void ToggleButton(const char* str_id, bool* v, color clr, ImFont* font = InVisible)
	{
		apply_padding(padding);
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = (ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2) - 7;
		float width = height * 1.55f;
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(clr.r, clr.g - 40, clr.b - 40, clr.a) : IM_COL32(133, 133, 133, 255); // if true/false and hovered
		else
			col_bg = *v ? IM_COL32(clr.r, clr.g, clr.b, clr.a) : IM_COL32(166, 166, 166, 255); // if true/false and not hovered

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius, IM_COL32(255, 255, 255, 255));
		ImGui::PushFont(font);
		draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .5 - 1.5), ImColor(255, 255, 255, 255), str_id);
		ImGui::PopFont();
		last_widget = 2;
	}

	static void OutlinedToggle(const char* str_id, bool* v, color clr, ImFont* font = InVisible)
	{
		apply_padding(padding);
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = (ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 3) - 7;
		float height2 = (ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 3) - 7;
		float width = height * 1.55f;
		float radius = height * 0.50f;
		float width2 = height2 * 1.56f;
		float radius2 = height2 * 0.51f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(clr.r, clr.g - 40, clr.b - 40, clr.a) : IM_COL32(133, 133, 133, 255); // if true/false and hovered
		else
			col_bg = *v ? IM_COL32(clr.r, clr.g, clr.b, clr.a) : IM_COL32(166, 166, 166, 255); // if true/false and not hovered


		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.7f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius, IM_COL32(255, 255, 255, 255));
		draw_list->AddCircle(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius, ImColor(0,0,0));
		ImGui::PushFont(font);
		draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .4 - 1.8), ImColor(0, 0, 0, 200), str_id);
		draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .5 - 1.5), ImColor(255, 255, 255, 255), str_id);
		ImGui::PopFont();
		last_widget = 2;
	}

	template <class t>

	// Currently broken will be fixed soon.

	static bool slider(const char* label, t* v, float v_min, float v_max)
	{
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		if (window->SkipItems)
			return false;

		ImGuiContext& g = *GImGui;
		const ImGuiStyle& style = g.Style;
		const ImGuiID id = window->GetID(label);
		const float w = ImGui::CalcItemWidth() * .65;

		const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
		auto text_pos = ImVec2(window->DC.CursorPos.x + 5, window->DC.CursorPos.y);

		window->DC.CursorPos.x -= real_padding.x;
		window->DC.CursorPos.x += window->Size.x - w - real_padding.x + 3; // positions to far right
		const ImRect frame_bb(ImVec2(window->DC.CursorPos.x, window->DC.CursorPos.y + label_size.y * .5 - 2), window->DC.CursorPos + ImVec2(w, label_size.y + 2));
		const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 2.0f));

		// NB- we don't call ItemSize() yet because we may turn into a text edit box below
		if (!ImGui::ItemAdd(total_bb, &id)) {
			ImGui::ItemSize(total_bb, style.FramePadding.y);
			return false;
		}

		const bool hovered = ImGui::IsHovered(frame_bb, id);
		if (hovered)
		{
			ImGui::SetHoveredID(id);

		}

		int decimal_precision = ImGui::ParseFormatPrecision("%.0f", 3);

		// Tabbing or CTRL-clicking on Slider turns it into an input box
		bool start_text_input = false;
		const bool tab_focus_requested = ImGui::FocusableItemRegister(window, g.ActiveId == id);
		if (tab_focus_requested || (hovered && g.IO.MouseClicked[0])) {
			ImGui::SetActiveID(id, window);
			ImGui::FocusWindow(window);

			if (tab_focus_requested || g.IO.KeyCtrl) {
				start_text_input = true;
				g.ScalarAsInputTextId = 0;
			}
		}
		if (start_text_input || (g.ActiveId == id && g.ScalarAsInputTextId == id))
			return ImGui::InputScalarAsWidgetReplacement(frame_bb, label, ImGuiDataType_Float, v, id, decimal_precision);

		ImGui::ItemSize(total_bb, style.FramePadding.y);

		// Actual slider behavior + render grab
		ImRect out_pos;
		float v_f = (float)*v;
		const bool value_changed = ImGui::SliderBehavior(frame_bb, id, "%.0f", std::is_same_v<t, int> ? &v_f : (float*)v, v_min, v_max, 1, decimal_precision, out_pos);
		std::is_same_v<t, int> ? *v = (int)v_f : true;

		// Display value using user-provided display format so user can add prefix/suffix/decorations to the value.
		char value_buf[64];
		const char* value_buf_end = value_buf + ImFormatString(value_buf, IM_ARRAYSIZE(value_buf), "%.0f", *v);
		if (label_size.x > 0.0f)
		{
			std::string text{ label };
			text.append(" (").append(std::is_same_v<t, int> ? std::to_string(*v) : value_buf).append(")");
			ImGui::RenderText(text_pos, text.c_str());
		}
		last_widget = 3;
		return value_changed;
	}
}
