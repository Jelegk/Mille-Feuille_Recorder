#pragma once

#include "imgui.h"

void SetImGuiStyle() {
  ImGuiStyle &style = ImGui::GetStyle();

  style.Alpha                     = 1.0f;
  style.DisabledAlpha             = 0.6f;
  style.WindowPadding             = ImVec2(12.0f, 12.0f);
  style.WindowRounding            = 0.0f;
  style.WindowBorderSize          = 0.0f;
  style.WindowMinSize             = ImVec2(20.0f, 20.0f);
  style.WindowTitleAlign          = ImVec2(0.5f,  0.5f);
  style.WindowMenuButtonPosition  = ImGuiDir_Left;
  style.ChildRounding             = 10.0f;
  style.ChildBorderSize           = 1.0f;
  style.PopupRounding             = 10.0f;
  style.PopupBorderSize           = 1.0f;
  style.FramePadding              = ImVec2(12.0f, 6.0f);
  style.FrameRounding             = 7.0f;
  style.FrameBorderSize           = 0.0f;
  style.ItemSpacing               = ImVec2(8.0f, 4.0f);
  style.ItemInnerSpacing          = ImVec2(4.0f, 4.0f);
  style.CellPadding               = ImVec2(4.0f, 20.0f);
  style.IndentSpacing             = 8.0f;
  style.ColumnsMinSpacing         = 14.0f;
  style.ScrollbarSize             = 3.0f; // TODO: try 0.0f
  style.ScrollbarRounding         = 3.0f;
  style.GrabMinSize               = 20.0f;
  style.GrabRounding              = 3.0f;
  style.TabRounding               = 4.0f;
  style.TabBorderSize             = 1.0f;
  // style.TabMinWidthForCloseButton = 20.0f;
  style.ColorButtonPosition       = ImGuiDir_Right;
  style.ButtonTextAlign           = ImVec2(0.5f, 0.5f);
  style.SelectableTextAlign       = ImVec2(0.0f, 0.0f);

  style.Colors[ImGuiCol_Text]                  = ImVec4(1.0f,         1.0f,         1.0f,         1.0f        );
  style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.29803923f,  0.29803923f,  0.29803923f,  1.0f        );
  style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.094419666f, 0.09441983f,  0.09442061f,  0.93991417f );
  style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.06437743f,  0.064377666f, 0.06437702f,  0.87124467f );
  style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.0643771f,   0.06437702f,  0.064377666f, 1.0f        );
  style.Colors[ImGuiCol_Border]                = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.0f,         0.0f,         0.0f,         0.0f        );
  style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.1254902f,   0.1254902f,   0.1254902f,   0.9411765f  );
  style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.14592272f,  0.068264276f, 0.07875874f,  0.87982833f );
  style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.20600861f,  0.062775165f, 0.08121727f,  0.93991417f );
  style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.1254902f,   0.1254902f,   0.1254902f,   0.9411765f  );
  style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.14163089f,  0.14162947f,  0.14162947f,  0.9411765f  );
  style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.10729611f,  0.10729504f,  0.10729504f,  0.87058824f );
  style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.105882354f, 0.105882354f, 0.105882354f, 0.9411765f  );
  style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.1254902f,   0.1254902f,   0.1254902f,   0.9411765f  );
  style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.09411765f,  0.09411765f,  0.09411765f,  0.9411765f  );
  style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  style.Colors[ImGuiCol_Button]                = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.16309011f,  0.068595834f, 0.08277003f,  0.8784314f  );
  style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_Header]                = ImVec4(0.1244635f,   0.124462254f, 0.124462254f, 0.9411765f  );
  style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.14163089f,  0.14162947f,  0.14162947f,  0.9411765f  );
  style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.14163089f,  0.14162947f,  0.14162947f,  0.9411765f  );
  style.Colors[ImGuiCol_Separator]             = ImVec4(0.29803923f,  0.29803923f,  0.29803923f,  0.9411765f  );
  style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.29803923f,  0.29803923f,  0.29803923f,  0.9411765f  );
  style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.29803923f,  0.29803923f,  0.29803923f,  0.9411765f  );
  style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.1254902f,   0.1254902f,   0.1254902f,   0.9411765f  );
  style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.1254902f,   0.1254902f,   0.1254902f,   0.9411765f  );
  style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.14117648f,  0.14117648f,  0.14117648f,  0.9411765f  );
  style.Colors[ImGuiCol_Tab]                   = ImVec4(0.13333334f,  0.13333334f,  0.13333334f,  0.9411765f  );
  style.Colors[ImGuiCol_TabHovered]            = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  // style.Colors[ImGuiCol_TabActive]             = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  // style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.09411765f,  0.09411765f,  0.09411765f,  0.9411765f  );
  // style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.09411765f,  0.09411765f,  0.09411765f,  0.9411765f  );
  style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.5019608f,   0.4392157f,   0.3137255f,   0.93991417f );
  style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_TableHeaderBg]         = ImVec4(0.14509805f,  0.06666667f,  0.078431375f, 0.8784314f  );
  style.Colors[ImGuiCol_TableBorderStrong]     = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_TableBorderLight]      = ImVec4(0.18884122f,  0.18883933f,  0.18883933f,  0.9411765f  );
  style.Colors[ImGuiCol_TableRowBg]            = ImVec4(0.0f,         0.0f,         0.0f,         0.0f        );
  style.Colors[ImGuiCol_TableRowBgAlt]         = ImVec4(1.0f,         1.0f,         1.0f,         0.015686275f);
  style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.5019608f,   0.4392157f,   0.3137255f,   0.9411765f  );
  // style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.20784314f,  0.0627451f,   0.08235294f,  0.9411765f  );
  style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.1882353f,   0.1882353f,   0.1882353f,   0.6866953f  );
  style.Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.1882353f,   0.1882353f,   0.1882353f,   0.19313306f );
  style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.1882353f,   0.1882353f,   0.1882353f,   0.3476395f  );
}
// TODO: Check if all ImGuiCol_ and style options are set
