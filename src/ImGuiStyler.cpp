#include "ImGuiStyler.hpp"

#include "SDL3/SDL_video.h"

void ImGuiStyler::StyleFormat() {
  ImGuiStyle &style = ImGui::GetStyle();

  float winScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
  style.ScaleAllSizes(winScale);
  style.FontScaleDpi = winScale;
// float       FontSizeBase;  // NOTE: set in main.cpp             // Current base font size before external global factors are applied. Use PushFont(NULL, size) to modify. Use ImGui::GetFontSize() to obtain scaled value.
// float       FontScaleMain;              // Main global scale factor. May be set by application once, or exposed to end-user.
// float       FontScaleDpi;               // Additional global scale factor from viewport/monitor contents scale. When io.ConfigDpiScaleFonts is enabled, this is automatically overwritten when changing monitor DPI.

  style.Alpha = 1.0f;// Global alpha applies to everything in Dear ImGui.
  style.DisabledAlpha = 0.6f;// Additional alpha multiplier applied by BeginDisabled(). Multiply over current value of Alpha.
  style.WindowPadding = ImVec2(12.0f, 12.0f);// Padding within a window.
  style.WindowRounding = 0.0f;// Radius of window corners rounding. Set to 0.0f to have rectangular windows. Large values tend to lead to variety of artifacts and are not recommended.
  style.WindowBorderSize = 0.0f;// Thickness of border around windows. Generally set to 0.0f or 1.0f. (Other values are not well tested and more CPU/GPU costly).
// float       WindowBorderHoverPadding;   // Hit-testing extent outside/inside resizing border. Also extend determination of hovered window. Generally meaningfully larger than WindowBorderSize to make it easy to reach borders.
  style.WindowMinSize = ImVec2(20.0f, 20.0f);// Minimum window size. This is a global setting. If you want to constrain individual windows, use SetNextWindowSizeConstraints().
  style.WindowTitleAlign = ImVec2(0.5f, 0.5f);// Alignment for title bar text. Defaults to (0.0f,0.5f) for left-aligned,vertically centered.
  style.WindowMenuButtonPosition = ImGuiDir_Left;// Side of the collapsing/docking button in the title bar (None/Left/Right). Defaults to ImGuiDir_Left.
  style.ChildRounding = 10.0f;// Radius of child window corners rounding. Set to 0.0f to have rectangular windows.
  style.ChildBorderSize = 1.0f;// Thickness of border around child windows. Generally set to 0.0f or 1.0f. (Other values are not well tested and more CPU/GPU costly).
  style.PopupRounding = 10.0f;// Radius of popup window corners rounding. (Note that tooltip windows use WindowRounding)
  style.PopupBorderSize = 1.0f;// Thickness of border around popup/tooltip windows. Generally set to 0.0f or 1.0f. (Other values are not well tested and more CPU/GPU costly).
  style.FramePadding = ImVec2(12.0f, 6.0f);// Padding within a framed rectangle (used by most widgets).
  style.FrameRounding = 7.0f;// Radius of frame corners rounding. Set to 0.0f to have rectangular frame (used by most widgets).
  style.FrameBorderSize = 1.0f;// Thickness of border around frames. Generally set to 0.0f or 1.0f. (Other values are not well tested and more CPU/GPU costly).
  style.ItemSpacing = ImVec2(8.0f, 4.0f);// Horizontal and vertical spacing between widgets/lines.
  style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);// Horizontal and vertical spacing between within elements of a composed widget (e.g. a slider and its label).
  style.CellPadding = ImVec2(4.0f, 20.0f); // Padding within a table cell. Cellpadding.x is locked for entire table. CellPadding.y may be altered between different rows.
// ImVec2      TouchExtraPadding;          // Expand reactive bounding box for touch-based system where touch position is not accurate enough. Unfortunately we don't sort widgets so priority on overlap will always be given to the first widget. So don't grow this too much!
  style.IndentSpacing = 8.0f;// Horizontal indentation when e.g. entering a tree node. Generally == (FontSize + FramePadding.x*2).
  style.ColumnsMinSpacing = 14.0f;// Minimum horizontal spacing between two columns. Preferably > (FramePadding.x + 1).
  style.ScrollbarSize = 0.0f;   // Width of the vertical scrollbar, Height of the horizontal scrollbar.
  style.ScrollbarRounding = 3.0f;// Radius of grab corners for scrollbar.
// float       ScrollbarPadding;           // Padding of scrollbar grab within its frame (same for both axises).
  style.GrabMinSize = 20.0f;// Minimum width/height of a grab box for slider/scrollbar.
  style.GrabRounding = 3.0f;// Radius of grabs corners rounding. Set to 0.0f to have rectangular slider grabs.
// float       LogSliderDeadzone;          // The size in pixels of the dead-zone around zero on logarithmic sliders that cross zero.
// float       ImageBorderSize;            // Thickness of border around Image() calls.
  style.TabRounding = 4.0f;// Radius of upper corners of a tab. Set to 0.0f to have rectangular tabs.
  style.TabBorderSize = 1.0f;// Thickness of border around tabs.
// float       TabRounding;                // Radius of upper corners of a tab. Set to 0.0f to have rectangular tabs.
// float       TabBorderSize;              // Thickness of border around tabs.
// float       TabMinWidthBase;            // Minimum tab width, to make tabs larger than their contents. TabBar buttons are not affected.
// float       TabMinWidthShrink;          // Minimum tab width after shrinking, when using ImGuiTabBarFlags_FittingPolicyMixed policy.
// float       TabCloseButtonMinWidthSelected;     // -1: always visible. 0.0f: visible when hovered. >0.0f: visible when hovered if minimum width.
// float       TabCloseButtonMinWidthUnselected;   // -1: always visible. 0.0f: visible when hovered. >0.0f: visible when hovered if minimum width. FLT_MAX: never show close button when unselected.
// float       TabBarBorderSize;           // Thickness of tab-bar separator, which takes on the tab active color to denote focus.
// float       TabBarOverlineSize;         // Thickness of tab-bar overline, which highlights the selected tab-bar.
// float       TableAngledHeadersAngle;    // Angle of angled headers (supported values range from -50.0f degrees to +50.0f degrees).
// ImVec2      TableAngledHeadersTextAlign;// Alignment of angled headers within the cell
// ImGuiTreeNodeFlags TreeLinesFlags;      // Default way to draw lines connecting TreeNode hierarchy. ImGuiTreeNodeFlags_DrawLinesNone or ImGuiTreeNodeFlags_DrawLinesFull or ImGuiTreeNodeFlags_DrawLinesToNodes.
// float       TreeLinesSize;              // Thickness of outlines when using ImGuiTreeNodeFlags_DrawLines.
// float       TreeLinesRounding;          // Radius of lines connecting child nodes to the vertical line.
                                // style.TabMinWidthForCloseButton = 20.0f;
  style.ColorButtonPosition = ImGuiDir_Right; // Side of the color button in the ColorEdit4 widget (left/right). Defaults to ImGuiDir_Right.
  style.ButtonTextAlign = ImVec2(0.5f, 0.5f); // Alignment of button text when button is larger than text. Defaults to (0.5f, 0.5f) (centered).
  style.SelectableTextAlign = ImVec2(0.0f, 0.0f); // Alignment of selectable text. Defaults to (0.0f, 0.0f) (top-left aligned). It's generally important to keep this left-aligned if you want to lay multiple items on a same line.
// float       SeparatorTextBorderSize;    // Thickness of border in SeparatorText()
// ImVec2      SeparatorTextAlign;         // Alignment of text within the separator. Defaults to (0.0f, 0.5f) (left aligned, center).
// ImVec2      SeparatorTextPadding;       // Horizontal offset of text from each edge of the separator + spacing on other axis. Generally small values. .y is recommended to be == FramePadding.y.
// ImVec2      DisplayWindowPadding;       // Apply to regular windows: amount which we enforce to keep visible when moving near edges of your screen.
// ImVec2      DisplaySafeAreaPadding;     // Apply to every windows, menus, popups, tooltips: amount where we avoid displaying contents. Adjust if you cannot see the edges of your screen (e.g. on a TV where scaling has not been configured).
// float       MouseCursorScale;           // Scale software rendered mouse cursor (when io.MouseDrawCursor is enabled). We apply per-monitor DPI scaling over this scale. May be removed later.
// bool        AntiAliasedLines;           // Enable anti-aliased lines/borders. Disable if you are really tight on CPU/GPU. Latched at the beginning of the frame (copied to ImDrawList).
// bool        AntiAliasedLinesUseTex;     // Enable anti-aliased lines/borders using textures where possible. Require backend to render with bilinear filtering (NOT point/nearest filtering). Latched at the beginning of the frame (copied to ImDrawList).
// bool        AntiAliasedFill;            // Enable anti-aliased edges around filled shapes (rounded rectangles, circles, etc.). Disable if you are really tight on CPU/GPU. Latched at the beginning of the frame (copied to ImDrawList).
// float       CurveTessellationTol;       // Tessellation tolerance when using PathBezierCurveTo() without a specific number of segments. Decrease for highly tessellated curves (higher quality, more polygons), increase to reduce quality.
// float       CircleTessellationMaxError; // Maximum error (in pixels) allowed when using AddCircle()/AddCircleFilled() or drawing rounded corner rectangles with no explicit segment count specified. Decrease for higher quality but more geometry.

// Behaviors
// (It is possible to modify those fields mid-frame if specific behavior need it, unlike e.g. configuration fields in ImGuiIO)
// float             HoverStationaryDelay;     // Delay for IsItemHovered(ImGuiHoveredFlags_Stationary). Time required to consider mouse stationary.
// float             HoverDelayShort;          // Delay for IsItemHovered(ImGuiHoveredFlags_DelayShort). Usually used along with HoverStationaryDelay.
// float             HoverDelayNormal;         // Delay for IsItemHovered(ImGuiHoveredFlags_DelayNormal). "
// ImGuiHoveredFlags HoverFlagsForTooltipMouse;// Default flags when using IsItemHovered(ImGuiHoveredFlags_ForTooltip) or BeginItemTooltip()/SetItemTooltip() while using mouse.
// ImGuiHoveredFlags HoverFlagsForTooltipNav;  // Default flags when using IsItemHovered(ImGuiHoveredFlags_ForTooltip) or BeginItemTooltip()/SetItemTooltip() while using keyboard/gamepad.
}
// TODO

void ImGuiStyler::StyleColorsCustom(ImVec4 txt,
                                    ImVec4 bgLr, ImVec4 bgL, ImVec4 bg, ImVec4 bgD, ImVec4 bgDr,
                                    ImVec4 accL, ImVec4 acc, ImVec4 accD,
                                    ImVec4 accAltL, ImVec4 accAlt, ImVec4 accAltD) {
  ImGuiStyle &style = ImGui::GetStyle();

  style.Colors[ImGuiCol_Text] = txt;
  style.Colors[ImGuiCol_TextDisabled] = bgLr;
  style.Colors[ImGuiCol_WindowBg] = bg;                                         // Background of normal windows
  style.Colors[ImGuiCol_ChildBg] = bgD;                                         // Background of child windows
  style.Colors[ImGuiCol_PopupBg] = bgL;                                         // Background of popups, menus, tooltips windows
  style.Colors[ImGuiCol_Border] = accL;
  style.Colors[ImGuiCol_BorderShadow] = acc;
  style.Colors[ImGuiCol_FrameBg] = accD;                                        // Background of checkbox, radio button, plot, slider, text input
  style.Colors[ImGuiCol_FrameBgHovered] = acc;
  style.Colors[ImGuiCol_FrameBgActive] = accL;
  style.Colors[ImGuiCol_TitleBg] = bgL;                                         // Title bar
  style.Colors[ImGuiCol_TitleBgActive] = bgLr;                                  // Title bar when focused
  style.Colors[ImGuiCol_TitleBgCollapsed] = bgD;                                // Title bar when collapsed
  style.Colors[ImGuiCol_MenuBarBg] = bgL;
  style.Colors[ImGuiCol_ScrollbarBg] = bgL;
  style.Colors[ImGuiCol_ScrollbarGrab] = accD;
  style.Colors[ImGuiCol_ScrollbarGrabHovered] = acc;
  style.Colors[ImGuiCol_ScrollbarGrabActive] = accL;
  style.Colors[ImGuiCol_CheckMark] = bgLr;                                      // Checkbox tick and RadioButton circle
  style.Colors[ImGuiCol_SliderGrab] = accD;
  style.Colors[ImGuiCol_SliderGrabActive] = accD;
  style.Colors[ImGuiCol_Button] = acc;
  style.Colors[ImGuiCol_ButtonHovered] = acc;
  style.Colors[ImGuiCol_ButtonActive] = accD;
  style.Colors[ImGuiCol_Header] = bgL;                                          // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
  style.Colors[ImGuiCol_HeaderHovered] = bgL;
  style.Colors[ImGuiCol_HeaderActive] = bgLr;
  style.Colors[ImGuiCol_Separator] = bgDr;
  style.Colors[ImGuiCol_SeparatorHovered] = bgDr;
  style.Colors[ImGuiCol_SeparatorActive] = bgDr;
  style.Colors[ImGuiCol_ResizeGrip] = bgL;                                      // Resize grip in lower-right and lower-left corners of windows.
  style.Colors[ImGuiCol_ResizeGripHovered] = bgLr;
  style.Colors[ImGuiCol_ResizeGripActive] = bgLr;
  style.Colors[ImGuiCol_InputTextCursor] = acc;                                 // InputText cursor/caret
  style.Colors[ImGuiCol_TabHovered] = bgLr;                                     // Tab background, when hovered
  style.Colors[ImGuiCol_Tab] = bgL;                                             // Tab background, when tab-bar is focused & tab is unselected
  style.Colors[ImGuiCol_TabSelected] = bgLr;                                    // Tab background, when tab-bar is focused & tab is selected
  style.Colors[ImGuiCol_TabSelectedOverline] = acc;                             // Tab horizontal overline, when tab-bar is focused & tab is selected
  style.Colors[ImGuiCol_TabDimmed] = bgD;                                       // Tab background, when tab-bar is unfocused & tab is unselected
  style.Colors[ImGuiCol_TabDimmedSelected] = bg;                                // Tab background, when tab-bar is unfocused & tab is selected
  style.Colors[ImGuiCol_TabDimmedSelectedOverline] = accD;                      //..horizontal overline, when tab-bar is unfocused & tab is selected
  style.Colors[ImGuiCol_PlotLines] = accAltD;
  style.Colors[ImGuiCol_PlotLinesHovered] = accAltL;
  style.Colors[ImGuiCol_PlotHistogram] = acc;
  style.Colors[ImGuiCol_PlotHistogramHovered] = accL;
  style.Colors[ImGuiCol_TableHeaderBg] = bgL;                                   // Table header background
  style.Colors[ImGuiCol_TableBorderStrong] = bgD;                               // Table outer and header borders (prefer using Alpha=1.0 here)
  style.Colors[ImGuiCol_TableBorderLight] = bgD;                                // Table inner borders (prefer using Alpha=1.0 here)
  style.Colors[ImGuiCol_TableRowBg] = bgL;                                      // Table row background (even rows)
  style.Colors[ImGuiCol_TableRowBgAlt] = bgL;                                   // Table row background (odd rows)
  style.Colors[ImGuiCol_TextLink] = accL;                                       // Hyperlink color
  style.Colors[ImGuiCol_TextSelectedBg] = accL;                                 // Selected text inside an InputText
  style.Colors[ImGuiCol_TreeLines] = accD;                                      // Tree node hierarchy outlines when using ImGuiTreeNodeFlags_DrawLines
  style.Colors[ImGuiCol_DragDropTarget] = accAltD;                              // Rectangle highlighting a drop target
  style.Colors[ImGuiCol_UnsavedMarker] = accAltL;                               // Unsaved Document marker (in window title and tabs)
  style.Colors[ImGuiCol_NavCursor] = accAlt;                                    // Color of keyboard/gamepad navigation cursor/rectangle, when visible
  style.Colors[ImGuiCol_NavWindowingHighlight] = accAltD;                       // Highlight window when using CTRL+TAB
  style.Colors[ImGuiCol_NavWindowingDimBg] = bgD;                               // Darken/colorize entire screen behind the CTRL+TAB window list, when active
  style.Colors[ImGuiCol_ModalWindowDimBg] = bgL;                                // Darken/colorize entire screen behind a modal window, when one is active
}

void ImGuiStyler::StyleColorsCustomDark() {
  ImVec4 text = ImVec4(0.9, 0.9, 0.9, 1.0f); // white

  ImVec4 bgLighter = ImVec4(0.217f, 0.204f, 0.184f, 1.0f); // grey
  ImVec4 bgLight =   ImVec4(0.180f, 0.165f, 0.149f, 1.0f);
  ImVec4 bg =        ImVec4(0.137f, 0.125f, 0.114f, 1.0f);
  ImVec4 bgDark =    ImVec4(0.094f, 0.086f, 0.078f, 1.0f);
  ImVec4 bgDarker =  ImVec4(0.055f, 0.047f, 0.043f, 1.0f);

  ImVec4 accentlight = ImVec4(0.612f, 0.035f, 0.161f, 1.0f); // red
  ImVec4 accent =      ImVec4(0.537f, 0.000f, 0.153f, 1.0f);
  ImVec4 accentDark =  ImVec4(0.408f, 0.000f, 0.137f, 1.0f);

  ImVec4 accentAltLight = ImVec4(0.784f, 0.620f, 0.427f, 1.0f); // beige
  ImVec4 accentAlt =      ImVec4(0.741f, 0.545f, 0.318f, 1.0f);
  ImVec4 accentAltDark =  ImVec4(0.600f, 0.427f, 0.227f, 1.0f);

  StyleColorsCustom(text, bgLighter, bgLight, bg, bgDark, bgDarker, accentlight, accent, accentDark, accentAltLight, accentAlt, accentAltDark);
}

void ImGuiStyler::StyleColorsCustomLight() {
  ImVec4 text = ImVec4(0.1, 0.1, 0.1, 1.0f); // black

  ImVec4 bgLighter = ImVec4(0.976f, 0.961f, 0.941f, 1.0f); // white
  ImVec4 bgLight =   ImVec4(0.953f, 0.922f, 0.890f, 1.0f);
  ImVec4 bg =        ImVec4(0.929f, 0.886f, 0.835f, 1.0f);
  ImVec4 bgDark =    ImVec4(0.871f, 0.788f, 0.694f, 1.0f);
  ImVec4 bgDarker =  ImVec4(0.839f, 0.741f, 0.624f, 1.0f);

  ImVec4 accentlight = ImVec4(0.612f, 0.035f, 0.161f, 1.0f); // red
  ImVec4 accent =      ImVec4(0.537f, 0.000f, 0.153f, 1.0f);
  ImVec4 accentDark =  ImVec4(0.408f, 0.000f, 0.137f, 1.0f);

  ImVec4 accentAltLight = ImVec4(0.282f, 0.208f, 0.122f, 1.0f); // brown
  ImVec4 accentAlt =      ImVec4(0.212f, 0.157f, 0.090f, 1.0f);
  ImVec4 accentAltDark =  ImVec4(0.141f, 0.106f, 0.059f, 1.0f);

  StyleColorsCustom(text, bgLighter, bgLight, bg, bgDark, bgDarker, accentlight, accent, accentDark, accentAltLight, accentAlt, accentAltDark);
}
