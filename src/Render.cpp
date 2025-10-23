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

  // NOTE: Window probably wont be resizeable
  // if (windowResized) { // FIX: must be edited between NewFrame() and its first element
  //   ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always, ImVec2(0.0f, 0.0f)); // NOTE: probably not necessary
  //   int *w = 0, *h = 0;
  //   SDL_GetWindowSizeInPixels(app->window, w, h);
  //   ImGui::SetNextWindowSize(ImVec2(*w, *h), ImGuiCond_Always);
  //   windowResized = false;
  // }

  const ImGuiWindowFlags imguiFlags = ImGuiWindowFlags_NoMove | // TODO: Do I like these?
                                      ImGuiWindowFlags_NoDecoration |
                                      ImGuiWindowFlags_NoSavedSettings;
  ImGui::Begin("main_window", nullptr, imguiFlags);
  // [ ] CONTENT
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
