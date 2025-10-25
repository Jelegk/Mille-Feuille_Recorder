#include "Render.hpp"

#include "SDL3/SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "implot.h"

#include "AppState.hpp"

#include <cstdarg>

void ImGuiTextAligned(float alignment, const char *fmt, ...) {
  float size = ImGui::CalcTextSize(fmt).x + ImGui::GetStyle().FramePadding.x * 2.0f;
  float avail = ImGui::GetContentRegionAvail().x;

  float offset = (avail - size) * alignment;
  if (offset > 0.0f)
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offset);

  va_list args;
  va_start(args, fmt);
  ImGui::Text(fmt, args);
  va_end(args);
}

void renderImGUIFrame(void *appstate) {
  AppState *app = (AppState *)appstate;

  // Start the Dear ImGui frame
  ImGui_ImplSDLRenderer3_NewFrame();
  ImGui_ImplSDL3_NewFrame();
  ImGui::NewFrame();

  // TODO: find a way to call only at SDL_AppInit()
  if (app->resizeImGUI) { // FIX: must be edited between NewFrame() and its first element
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always, ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(app->winWidth, app->winHeight), ImGuiCond_Always);
    app->resizeImGUI = false;
  }

  const ImGuiWindowFlags imguiFlags = ImGuiWindowFlags_NoMove |
                                      ImGuiWindowFlags_NoDecoration |
                                      // ImGuiWindowFlags_NoBackground |
                                      ImGuiWindowFlags_NoSavedSettings;
  ImGui::Begin("main_window", nullptr, imguiFlags);
  {
    float  winWidth = ImGui::GetContentRegionAvail().x;
    ImVec2 headerBtnSize = ImVec2(winWidth / 2, winWidth / 7);
    ImGui::Button("MENU", headerBtnSize);
    ImGui::SameLine();
    ImGui::Button("SAVE", headerBtnSize);

    ImGui::NewLine();
    ImGuiTextAligned(0.5f, "New Recording");

    ImVec2 bodySize = ImGui::GetContentRegionAvail();
    ImGui::BeginChild("body", bodySize, ImGuiChildFlags_NavFlattened);
    {
      // ImGui::BeginTable(); // TODO: see if preferred down the line

      int arrayRotateOffset = 0;
      int values[25] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 7, 4, 5, 7, 3, 7, 8, 6, 1, 4, 6, 9, 4, 7, 9, 4 };
      if (ImPlot::BeginPlot("track_01", ImVec2(-1, 0), ImPlotFlags_CanvasOnly | ImPlotFlags_NoInputs)) {
        ImPlot::SetupAxis(ImAxis_X1, nullptr, ImPlotAxisFlags_NoDecorations);
        ImPlot::SetupAxis(ImAxis_Y1, nullptr, ImPlotAxisFlags_NoDecorations);

        ImPlot::PlotBars("plot_01", values, IM_ARRAYSIZE(values), 0.8f, 0, ImPlotBarsFlags_None, arrayRotateOffset);
        ImPlot::EndPlot();
      }
    }
    ImGui::EndChild();
  }
  ImGui::End();

  // Rendering
  ImGui::Render();
  SDL_SetRenderScale(app->renderer, app->imGuiIO->DisplayFramebufferScale.x, app->imGuiIO->DisplayFramebufferScale.y);
  SDL_SetRenderDrawColorFloat(app->renderer, 0.0f, 0.0f, 0.0f, SDL_ALPHA_TRANSPARENT_FLOAT);
  SDL_RenderClear(app->renderer);
  ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), app->renderer);
  SDL_RenderPresent(app->renderer);
}
