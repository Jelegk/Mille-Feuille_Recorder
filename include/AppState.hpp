#pragma once

#include "SDL3/SDL_video.h"
#include "SDL3/SDL_render.h"
#include "imgui.h"

struct AppState {
  SDL_Window   *window;
  SDL_Renderer *renderer;
  ImGuiIO      *imGuiIO;
  // TODO: ImStyle? and replace all ImGui::GetStyle() by this?

  ~AppState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }
};
