#include "Render.hpp"

#include "SDL3/SDL.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

#include "AppState.hpp"

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

  const ImGuiWindowFlags imguiFlags = ImGuiWindowFlags_NoNav |
                                      ImGuiWindowFlags_NoMove |
                                      ImGuiWindowFlags_NoDecoration |
                                      // ImGuiWindowFlags_NoBackground |
                                      ImGuiWindowFlags_NoSavedSettings;
  ImGui::Begin("main_window", nullptr, imguiFlags);

  // MARK: ImGUI content here
  ImGui::Button("OPEN");
  float tmp = ImGui::GetItemRectSize().x;
  ImGui::SameLine(0, ImGui::GetContentRegionAvail().x - tmp * 2);
  ImGui::Button("SAVE");

  ImGui::ShowStyleEditor();

  ImGui::End();

  // Rendering
  ImGui::Render();
  SDL_SetRenderScale(app->renderer, app->imGuiIO->DisplayFramebufferScale.x, app->imGuiIO->DisplayFramebufferScale.y);
  SDL_SetRenderDrawColorFloat(app->renderer, 0.0f, 0.0f, 0.0f, SDL_ALPHA_TRANSPARENT_FLOAT);
  SDL_RenderClear(app->renderer);
  ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), app->renderer);
  SDL_RenderPresent(app->renderer);
}

void alignNextImguitextElement(const char *textElement, float alignment) {
  float size = ImGui::CalcTextSize(textElement).x + ImGui::GetStyle().FramePadding.x * 2.0f;
  float avail = ImGui::GetContentRegionAvail().x;

  float offset = (avail - size) * alignment;
  if (offset > 0.0f)
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offset);
}
