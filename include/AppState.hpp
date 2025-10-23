#pragma once

#include "SDL3/SDL_video.h"
#include "SDL3/SDL_render.h"
#include "imgui.h"

struct AppState {
  SDL_Window   *window;
  SDL_Renderer *renderer;
  const int     winWidth = 360;
  const int     winHeight = 800;

  ImGuiIO *imGuiIO;
  // TODO: ImGuiStyle *imGuiStyle; replace all ImGui::GetStyle() by this?
  bool     resizeImGUI = true;

  ~AppState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
};
