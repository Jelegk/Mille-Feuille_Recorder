#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

#include "AppState.hpp"
#include "ImGuiStyler.hpp"
#include "ProFontWindows-ttf.h"
#include "Events.hpp"
#include "Render.hpp"

#include <iostream>

// MARK: SDL_AppInit
SDL_AppResult SDL_AppInit([[maybe_unused]] void **appstate, [[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  if (!SDL_SetAppMetadata("Mille-Feuille Recorder", "1.0", "com.gde.milfeuille-rec"))
    SDL_Log("Warning: SDL_SetAppMetadata(): %s\n", SDL_GetError());

  AppState *app = new AppState();
  *appstate = app;

  // --------------------------------- SDL -------------------------------------
  if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
    SDL_Log("Error: SDL_InitSubSystem(): %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  float           winScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
  SDL_WindowFlags winFlags = SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_TRANSPARENT;
  if (!SDL_CreateWindowAndRenderer("Mille-Feuille Recorder", int(app->winWidth * winScale), int(app->winHeight * winScale), winFlags, &app->window, &app->renderer)) {
    SDL_Log("Error: SDL_CreateWindowAndRenderer(): %s\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (!SDL_SetRenderVSync(app->renderer, 1))
    SDL_Log("Warning: SDL_SetRenderVSync(): %s\n", SDL_GetError());

  if (!SDL_SetWindowPosition(app->window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED))
    SDL_Log("Warning: SDL_SetWindowPosition(): %s\n", SDL_GetError());
  if (!SDL_ShowWindow(app->window))
    SDL_Log("Error: SDL_ShowWindow(): %s\n", SDL_GetError());

  // -------------------------------- ImGUI ------------------------------------
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  app->imGuiIO = &ImGui::GetIO();
  app->imGuiIO->IniFilename = nullptr; // Suppress Dear ImGui's automatic ini file handling
  app->imGuiIO->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // app->imGuiIO->ConfigDpiScaleFonts = true; // TODO: find wehre it exists. For now, it is manually changed on SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED

  // TODO: test if SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED is sent at init, otherwise keep this block
  ImGuiStyle &style = ImGui::GetStyle();
  style.ScaleAllSizes(winScale);
  style.FontScaleDpi = winScale;

  ImGuiStyler::StyleFormat();
  // TODO: test if SDL_EVENT_SYSTEM_THEME_CHANGED is sent at init, otherwise keep this line
  SDL_GetSystemTheme() == SDL_SYSTEM_THEME_LIGHT ? ImGuiStyler::StyleColorsCustomLight() : ImGuiStyler::StyleColorsCustomDark();

  ImGui_ImplSDL3_InitForSDLRenderer(app->window, app->renderer);
  ImGui_ImplSDLRenderer3_Init(app->renderer);

  // TODO: Consider Noto font
  ImFont *f = app->imGuiIO->Fonts->AddFontFromMemoryCompressedTTF(proFontWindows_data, proFontWindows_size);
  if (f == nullptr) {
    SDL_Log("Warning: AddFontFromMemoryCompressedTTF(proFontWindows) failed. Using default font.");
    app->imGuiIO->Fonts->AddFontDefault();
    style.FontSizeBase = 13.0f;
  }
  else {
    app->imGuiIO->FontDefault = f;
    style.FontSizeBase = 20.0f;
  }

  // ---------------------------------------------------------------------------

  return SDL_APP_CONTINUE;
}


// MARK: SDL_AppEvent
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
  ImGui_ImplSDL3_ProcessEvent(event); // Forward event to Imgui
  return processEvent(appstate, event);
}


// MARK: SDL_AppIterate
SDL_AppResult SDL_AppIterate(void *appstate) {
  // TODO: is it necessary with SDL_EVENT_WINDOW_HIDDEN or SDL_EVENT_WINDOW_MINIMIZED ?
  // if (SDL_GetWindowFlags(app->window) & SDL_WINDOW_MINIMIZED) {
  //   SDL_Delay(100);
  //   return SDL_APP_CONTINUE;
  // }

  renderImGUIFrame(appstate);

  return SDL_APP_CONTINUE;
}


// MARK: SDL_AppQuit
void SDL_AppQuit(void *appstate, [[maybe_unused]] SDL_AppResult result) {
  ImGui_ImplSDLRenderer3_Shutdown();
  ImGui_ImplSDL3_Shutdown();
  ImGui::DestroyContext();

  delete (AppState *)appstate;
}

// [ ] Have entire ImGUI content scale up/down with SDL window resize
// [ ] Integrate plotting element for audio loudness
// [ ]  ┕ (current input loudmeter? track style.framebg color dynamically changes if loud?)
// [ ] Plan "flexbox" (child widget?) layout with mutliple tracks
// [ ] Revise stylesheet
// [ ] Touch inputs
// [ ] Record voice (acces to mic)
// [ ]  ┕ (add sensor functionality?)
// [ ] Buffers for layers
// [ ] I/O (saving on filesystem)
// [ ] Run on Android
