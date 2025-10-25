#include "ImPlotStyler.hpp"

#include "imgui.h"
#include "implot.h"

void ImPlotStyler::StyleFormat() {
  ImPlotStyle &style = ImPlot::GetStyle();

  // item styling variables
  style.FillAlpha = 1.0f;                   // foreground opacity
  // plot styling variables
  style.PlotBorderSize = 0;
  style.PlotPadding = ImVec2(0, 0);
  style.FitPadding = ImVec2(0.05f, 0.5f);   // padding between plot and frame border, in %
  style.PlotDefaultSize = ImVec2(300, 90); // frame default size, in px
  style.PlotMinSize = style.PlotDefaultSize;
}

void ImPlotStyler::StyleColors() {
  ImGuiStyle  &gStyle = ImGui::GetStyle();
  ImPlotStyle &pStyle = ImPlot::GetStyle();

  // item styling colors
  pStyle.Colors[ImPlotCol_Fill] = gStyle.Colors[ImGuiCol_FrameBg];           // accent color, regular
  // plot styling colors
  pStyle.Colors[ImPlotCol_PlotBg] = ImVec4(0, 0, 0, 0);
  pStyle.Colors[ImPlotCol_FrameBg] = gStyle.Colors[ImGuiCol_FrameBgHovered]; // accent color, dark
}
