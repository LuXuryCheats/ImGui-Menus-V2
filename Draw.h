float vipr1 = 10;
float vipr2 = 10;
float vipr3 = 10;
int viprbone = 66;
int viprtype = 1;
float viprcircle = 4;
int vipraccuracy = 30;
#include "Config.h"
// config issue guys.
bool Checkbox = false;
float Slider;

auto wndflags = ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize; //| ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar;


// depending on all fonts text will be uncentered 

void Config::Tutorial()
{
	auto& style = ImGui::GetStyle();
	style.FrameRounding = 4.0f;
	style.WindowBorderSize = 0.0f;
	style.PopupBorderSize = 0.0f;
	style.GrabRounding = 4.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.73f, 0.75f, 0.74f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.47f, 0.22f, 0.22f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.34f, 0.16f, 0.16f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.71f, 0.39f, 0.39f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.84f, 0.66f, 0.66f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.47f, 0.22f, 0.22f, 0.65f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.65f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
	colors[ImGuiCol_Header] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.65f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);

	ImGui::SetNextWindowSize({ 600, 400 });
	ImGui::Begin("Tutorial", 0);
	ImGui::Text("Hello, Thank you for downloading my menu pack!");
	ImGui::Text("if you didnt download from my github here it is https://github.com/LuXuryCheats/.");
	ImGui::Text("lets get started on the menu tutorial");
	ImGui::Separator();
	ImGui::Checkbox("Checkbox Example", &Checkbox); ImGui::SameLine(); ImGui::Text("this text is beside the checkbox by doing ImGui::SameLine(); if you click the\ncheckbox a slider will show! as you can see i also made the text go down a line\n by doing \\\ n");
	if (Checkbox)
	{
		ImGui::SliderFloat("Slider Example", &Slider, 0.0f, 300000.f);
	}
	ImGui::Text("");
	ImGui::Text("To Create a Checkbox do ImGui::CheckBox(Quotation Mark Text Quotation Mark, &SettingName);");
	ImGui::Text("To Create a Slider do ImGui::SliderFloat(Quotation Mark Text Quotation Mark, &SettingName, 0.f, 2000.f);");
	ImGui::Separator();
	ImGui::Text("Thats it for the basics! hopefully this helped yall new people. its literally basic imgui.");
	ImGui::Separator();
	ImGui::End();
	ImGui::EndFrame();
}

ImVec2 p; // Super Important for Moveable Customs

void Config::Viper()
{
	// Font Used: arial bold |Size: 15 to 16| io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arialbd.ttf", 15);

	int x = 20;
	int y = 30;

	std::string TITLETEXT = xorstr("                          Fortnite");

	Draw::BackgroundFilled(x, y, 273, -2, &Draw::Color.red);
	Draw::BackgroundFilled(x, y, 273, 520, &Draw::Color.red);
	Draw::BackgroundFilled(x, y, -2, 520, &Draw::Color.red);
	Draw::BackgroundFilled(x, y, 271, 518, &Draw::Color.black);
	Draw::RegularText(x + 4, y + 4, &Draw::Color.white, TITLETEXT.c_str());

	std::string CHESTDIST = std::to_string(vipr1);
	std::string SMOOTH = std::to_string(vipr2);
	std::string DIST = std::to_string(vipr3);
	std::string BONE = std::to_string(viprbone);
	std::string TYPE = std::to_string(viprtype);
	std::string SILENT_ACCURACY = std::to_string(vipraccuracy);
	std::string FORTNITEFOVXD = std::to_string(viprcircle);

	Draw::RegularText(x + 6, y + 45, &Draw::Color.white, xorstr("Chest ESP ")); Draw::RegularText(x + 234, y + 45, &Draw::Color.white, xorstr("  ON"));
	Draw::RegularText(x + 6, y + 65, &Draw::Color.white, xorstr("Chest ESP Distance "));  Draw::RegularText(x + 198, y + 65, &Draw::Color.white, CHESTDIST.c_str());
	Draw::RegularText(x + 6, y + 85, &Draw::Color.white, xorstr("Aimbot ")); Draw::RegularText(x + 234, y + 85, &Draw::Color.white, xorstr("  ON"));
	Draw::RegularText(x + 6, y + 105, &Draw::Color.white, xorstr("Aim Smooth ")); Draw::RegularText(x + 205, y + 105, &Draw::Color.white, SMOOTH.c_str());
	Draw::RegularText(x + 6, y + 125, &Draw::Color.white, xorstr("Max Aimbot Distance "));  Draw::RegularText(x + 198, y + 125, &Draw::Color.white, DIST.c_str());
	Draw::RegularText(x + 6, y + 145, &Draw::Color.white, xorstr("Aimbot Bone "));  Draw::RegularText(x + 250, y + 145, &Draw::Color.white, BONE.c_str());
	Draw::RegularText(x + 6, y + 165, &Draw::Color.white, xorstr("Aimbot Type "));  Draw::RegularText(x + 250, y + 165, &Draw::Color.white, TYPE.c_str());
	Draw::RegularText(x + 6, y + 185, &Draw::Color.white, xorstr("Silent Accuracy "));  Draw::RegularText(x + 238, y + 185, &Draw::Color.white, SILENT_ACCURACY.c_str());
	Draw::RegularText(x + 6, y + 205, &Draw::Color.white, xorstr("Rage Silent ")); Draw::RegularText(x + 234, y + 205, &Draw::Color.white, xorstr("  ON"));
	Draw::RegularText(x + 6, y + 225, &Draw::Color.white, xorstr("Fake Crosshair ")); Draw::RegularText(x + 234, y + 225, &Draw::Color.white, xorstr("  ON"));
	Draw::RegularText(x + 6, y + 245, &Draw::Color.white, xorstr("FOV Circle ")); Draw::RegularText(x + 234, y + 245, &Draw::Color.white, xorstr("  ON"));
	Draw::RegularText(x + 6, y + 265, &Draw::Color.white, xorstr("FOV "));  Draw::RegularText(x + 198, y + 265, &Draw::Color.white, FORTNITEFOVXD.c_str());
}

void Config::ElectricPlug()
{
	// Font Used: Tahoma |Size: 18 to 17| io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 18);

	int x = 30;
	int y = 20;

	std::string Title = xorstr(" ElectricPlug");

	Draw::BackgroundFilled(x, y, -2, -2, &Draw::Color.blue);
	Draw::BackgroundFilled(x, y, 243, -2, &Draw::Color.blue);
	Draw::BackgroundFilled(x, y, 243, 320, &Draw::Color.blue);
	Draw::BackgroundFilled(x, y, -2, 320, &Draw::Color.blue);
	Draw::BackgroundFilled(x, y, 241, 318, &Draw::Color.black);
	Draw::OutlinedRBGText(x + 4, y + 4, ImColor(255,255,255), Title.c_str());

	Draw::RegularText(x + 7, y + 45, &Draw::Color.white, xorstr("Player ESP: "));
	Draw::RegularText(x + 7, y + 65, &Draw::Color.white, xorstr("Player Lines: "));
	Draw::RegularText(x + 7, y + 85, &Draw::Color.white, xorstr("FOV circle: "));
	Draw::RegularText(x + 7, y + 105, &Draw::Color.white, xorstr("Aimbot: "));
	Draw::RegularText(x + 7, y + 125, &Draw::Color.white, xorstr("Aimbot FOV: "));
	Draw::RegularText(x + 7, y + 145, &Draw::Color.white, xorstr("Aimbot key: "));
	Draw::RegularText(x + 7, y + 165, &Draw::Color.white, xorstr("Aimbot smoothing: "));
}

void Config::Desync()
{

	auto& style = ImGui::GetStyle();
	style.WindowBorderSize = 0.2f;
	style.WindowRounding = 0.0f;

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImColor(255,255,255);
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.94f);
	colors[ImGuiCol_Button] = ImColor(1, 51, 188);
	colors[ImGuiCol_CheckMark] = ImColor(65, 149, 249);
	colors[ImGuiCol_FrameBg] = ImColor(1, 51, 188);
	colors[ImGuiCol_FrameBgHovered] = ImColor(66, 150, 250);
	colors[ImGuiCol_FrameBgActive] = ImColor(1, 51, 188);
	
	ImGui::SetNextWindowSize({ 400, 288 });
	ImGui::Begin("Desync", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
	{
		ImGui::Columns(1);
		ImGui::Button("aimbot", ImVec2(80, 20));
		ImGui::Button("visual", ImVec2(80, 20));
		ImGui::Button("misc", ImVec2(80, 20));
		ImGui::Button("loot", ImVec2(80, 20));
		ImGui::Button("key", ImVec2(80, 20));
	}
	ImGui::End();
	ImGui::EndFrame();
}

void Config::CSGOCustom()
{

}

bool enabled = true;
bool disabled = false;
// fixed in v3
void SimpleBox(int x, int y, ImColor color, const char* str, bool v)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = Draw::string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(p.x + x + 23, p.y + y + -6), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(p.x + x + 23, p.y + y + -6), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(p.x + x + 23, p.y + y + -6), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());

	ImGui::Checkbox(str, &v);

	Draw::BackgroundFilledRBG(p.x + x, p.y + y, 15, 10, ImColor(0, 255, 150, 255));
	Draw::BackgroundRBGOutline(p.x + x, p.y + y, 15, 10, ImColor(0, 0, 0), 3);
	Draw::BackgroundRBGOutline(p.x + x, p.y + y, 15, 10, ImColor(255, 255, 255, 200), 1);

}


static int tabs;
bool aimbot = false;
bool esp = false;
bool color = false;
void keys()
{

}
int fovsize = 100.f;
int aimdis = 523.f;
std::string fovcircle = std::to_string(fovsize);
std::string distance = std::to_string(aimdis);
void simple2drawing()
{
	// title and bg
	Draw::BackgroundRBGOutline(p.x + 5, p.y + 5, 420, 350, ImColor(60, 60, 60), 2);
	Draw::BackgroundFilledRBG(p.x + 5, p.y + 5, 420, 350, ImColor(31, 31, 31, 255));
	Draw::BackgroundFilledRBG(p.x + 5, p.y + 5, 420, 30, ImColor(18, 18, 18, 255));
	Draw::ShadowRGBText(p.x + 15, p.y + 10, ImColor(255, 255, 255, 255), ("menus-version-2 | monkey brain creations"));

	// child 1
	Draw::BackgroundRBGOutline(p.x + 15, p.y + 42, 120, 303, ImColor(60, 60, 60), 2);
	Draw::BackgroundFilledRBG(p.x + 15, p.y + 42, 120, 303, ImColor(18, 18, 18, 255));
	Draw::ShadowRGBText(p.x + 50, p.y + 100, ImColor(255, 255, 255), ("aimbot"));
	Draw::ShadowRGBText(p.x + 50, p.y + 140, ImColor(255, 255, 255), ("visuals"));
	Draw::ShadowRGBText(p.x + 54, p.y + 180, ImColor(255, 255, 255), ("misc"));
	// child 2
	Draw::BackgroundRBGOutline(p.x + 145, p.y + 42, 270, 303, ImColor(60, 60, 60), 2);
	Draw::BackgroundFilledRBG(p.x + 145, p.y + 42, 270, 303, ImColor(18, 18, 18, 255));

	// im not using ImGui::Text its obviouslt ImGui::Spacing
	// these are always autistic lmao
	if (tabs == 1)
	{
		// add slider + checkbox yourself for now please adding in v3
		Draw::ShadowRGBText(p.x + 50, p.y + 100, ImColor(200, 0, 255), ("aimbot"));
		Draw::ShadowRGBText(p.x + 160, p.y + 50, ImColor(255, 255, 255), ("aimbot fov:"));
		Draw::ShadowRGBText(p.x + 235, p.y + 50, ImColor(255, 255, 255), fovcircle.c_str());
		Draw::ShadowRGBText(p.x + 160, p.y + 70, ImColor(255, 255, 255), ("aimbot dis:"));
		Draw::ShadowRGBText(p.x + 235, p.y + 70, ImColor(255, 255, 255), distance.c_str());
	}
	if (tabs == 2)
	{
		Draw::ShadowRGBText(p.x + 50, p.y + 140, ImColor(200, 0, 255), ("visuals"));
		Draw::ShadowRGBText(p.x + 160, p.y + 50, ImColor(255, 255, 255), ("player esp:"));
	}
	if (tabs == 3)
	{
		Draw::ShadowRGBText(p.x + 54, p.y + 180, ImColor(200, 0, 255), ("misc"));
		Draw::ShadowRGBText(p.x + 160, p.y + 50, ImColor(255, 255, 255), ("no spread:"));
		//SimpleBox(160, 50, ImColor(255, 255, 255, 255), "Reticle", aimbot);
	}
}

void simple2menu()
{
	ImGui::Text("");
	ImGui::Text("");
	ImGui::Text("");
	ImGui::Text("");
	ImGui::Text("    "); ImGui::SameLine(); if (ImGui::Button("tab 1", ImVec2(60, 26))) tabs = 1;
	ImGui::Text("");
	ImGui::Text("    "); ImGui::SameLine(); if (ImGui::Button("tab 2", ImVec2(60, 26))) tabs = 2;
	ImGui::Text("    "); ImGui::SameLine(); if (ImGui::Button("tab 3", ImVec2(60, 26))) tabs = 3;

	Draw::Checkbox("q", &aimbot);
}

// not complete.
void Config::Simple()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImColor();
	keys();
	ImGui::SetNextWindowSize({ 300, 460 });
	ImGui::Begin("#Fortnite", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

	int x = 30;
	int y = 20;

	p = ImGui::GetWindowPos();
	// Main
	Draw::BackgroundRBGOutline(p.x + 5, p.y + 5, 300, 400, ImColor(0, 0, 0), 3);
	Draw::BackgroundFilledRBG(p.x + 5, p.y + 5, 300, 400, ImColor(34, 34, 34));
	Draw::BackgroundRBGOutline(p.x + 5, p.y + 5, 300, 400, ImColor(44, 44, 44), 2);

	// Separator
	Draw::BackgroundRBGOutline(p.x + 5, p.y + 40, 300, 1, ImColor(0, 0, 0), 1);
	Draw::BackgroundFilledRBG(p.x + 5, p.y + 40, 300, 1, ImColor(10, 255, 190));
	Draw::ShadowRGBText(p.x + 8, p.y + 12, ImColor(185, 185, 185, 255), ("  fart.club v2 | public external"));

	// Child
	Draw::BackgroundRBGOutline(p.x + 15, p.y + 50, 280, 300, ImColor(0, 0, 0), 3);
	Draw::BackgroundFilledRBG(p.x + 15, p.y + 50, 280, 300, ImColor(28, 28, 28));
	Draw::BackgroundRBGOutline(p.x + 15, p.y + 50, 280, 300, ImColor(48, 48, 48), 1);

	// Tabs
	Draw::BackgroundRBGOutline(p.x + 90, p.y + 355, 130, 37, ImColor(0, 0, 0), 3);
	Draw::BackgroundFilledRBG(p.x + 90, p.y + 355, 130, 37, ImColor(28, 28, 28));
	Draw::BackgroundRBGOutline(p.x + 90, p.y + 355, 130, 37, ImColor(48, 48, 48), 1);

	Draw::ShadowRGBText(p.x + 105, p.y + 362, ImColor(255, 255, 255, 255), ("   undetected"));

	Draw::BackgroundRBGOutline(p.x + 5, p.y + 410, 300, 37, ImColor(0, 0, 0), 3);
	Draw::BackgroundFilledRBG(p.x + 5, p.y + 410, 300, 37, ImColor(34, 34, 34));
	Draw::BackgroundRBGOutline(p.x + 5, p.y + 410, 300, 37, ImColor(48, 48, 48), 1);

	Draw::ShadowRGBText(p.x + 50, p.y + 417, ImColor(185, 185, 185, 255), (" |  aimbot"));
	Draw::ShadowRGBText(p.x + 120, p.y + 417, ImColor(185, 185, 185, 255), ("   visuals"));
	Draw::ShadowRGBText(p.x + 190, p.y + 417, ImColor(185, 185, 185, 255), ("  colors  |"));

	// add tabs yourself sorry.

	if (tabs == 1)
	{
		Draw::ShadowRGBText(p.x + 115, p.y + 55, ImColor(185, 185, 185, 255), ("   aimbot"));
		Draw::ShadowRGBText(p.x + 20, p.y + 60, ImColor(0, 255, 150, 255), ("_________________________________"));
		Draw::ShadowRGBText(p.x + 50, p.y + 417, ImColor(255, 255, 255, 255), (" |  aimbot"));
		SimpleBox(30, 100, ImColor(255, 255, 255, 255), "Aimbot", Checkbox);
		SimpleBox(30, 120, ImColor(255, 255, 255, 255), "Aimbot FOV", esp);
		SimpleBox(30, 140, ImColor(255, 255, 255, 255), "Crosshair", aimbot);
		SimpleBox(30, 160, ImColor(255, 255, 255, 255), "Reticle", aimbot);
	}
	if (tabs == 2)
	{
		Draw::ShadowRGBText(p.x + 115, p.y + 55, ImColor(185, 185, 185, 255), ("     esp"));
		Draw::ShadowRGBText(p.x + 20, p.y + 60, ImColor(0, 255, 150, 255), ("_________________________________"));
		Draw::ShadowRGBText(p.x + 120, p.y + 417, ImColor(255, 255, 255, 255), ("   visuals"));
		SimpleBox(30, 100, ImColor(255, 255, 255, 255), "Player BOX", Checkbox);
	}
	if (tabs == 3)
	{
		Draw::ShadowRGBText(p.x + 115, p.y + 55, ImColor(185, 185, 185, 255), ("   colors"));
		Draw::ShadowRGBText(p.x + 20, p.y + 60, ImColor(0, 255, 150, 255), ("_________________________________"));
		Draw::ShadowRGBText(p.x + 190, p.y + 417, ImColor(255, 255, 255, 255), ("  colors  |"));
	}

	ImGui::End();
	ImGui::EndFrame();
}
void Config::Simple2()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImColor();
	keys();
	ImGui::SetNextWindowSize({ 420, 350 });
	ImGui::Begin("#Fortnite", NULL, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

	int x = 30;
	int y = 20;

	p = ImGui::GetWindowPos();

	simple2drawing();
	simple2menu();

	ImGui::End();
	ImGui::EndFrame();
}

void Config::CheatLoverz()
{

}
float fov_size = 300.0f;
void tutorial()
{
	int x = 30;
	int y = 20;
	Draw::BackgroundLowOpacity(x + 4, y + 4, 200, 300, &Draw::Color.black);
	Draw::BackgroundLowOpacity(x + 4, y + 4, 200, 300, &Draw::Color.black);
	Draw::BackgroundOutline(x + 4, y + 4, 200, 300, &Draw::Color.black, 1);
	Draw::BackgroundOutline(x + 4, y + 4, 200, 20, &Draw::Color.black, 2);
	Draw::BackgroundFilledRBG(x + 4, y + 4, 200, 20, ImColor(36, 179, 124));
	
	std::string size = std::to_string(fov_size);
	// title bar
	Draw::RegularText(x + 7, y + 5, &Draw::Color.black, xorstr("Example"));

	Draw::RegularText(x + 16, y + 45, &Draw::Color.white, xorstr("Aimbot:")); Draw::RegularText(x + 16, y + 45, &Draw::Color.green, xorstr("                         ON"));
	Draw::RegularText(x + 16, y + 65, &Draw::Color.white, xorstr("FOV Circle:")); Draw::RegularText(x + 16, y + 65, &Draw::Color.green, xorstr("                         ON"));
	Draw::RegularText(x + 15, y + 85, &Draw::Color.white, xorstr("ESP:"));  Draw::RegularText(x + 16, y + 85, &Draw::Color.green, xorstr("                         ON"));
	Draw::RegularText(x + 15, y + 105, &Draw::Color.white, xorstr("Snaplines:")); Draw::RegularText(x + 13, y + 105, &Draw::Color.red, xorstr("                          OFF"));
	Draw::RegularText(x + 16, y + 125, &Draw::Color.white, xorstr("FOV Size: ")); Draw::RegularText(x + 84, y + 125, &Draw::Color.white, size.c_str());

}