#include "Events.hpp"

#include "SDL3/SDL_locale.h"
#include "SDL3/SDL_log.h"
#include "imgui.h"

#include "AppState.hpp"
#include "ImGuiStyler.hpp"

#include <cstring>

                           // TODO remove maybe_unused once its used. currently there to avoid error with -Weror
SDL_AppResult processEvent([[maybe_unused]] void *appstate, SDL_Event *event) {
  AppState *app = (AppState *)appstate;

  switch (event->type) {
    case SDL_EVENT_QUIT :
      return SDL_APP_SUCCESS;
      break;

    // These events have special meaning on iOS and Android: see SDL_EventType definition in SDL_events.h, README-ios.md and README-android.md for details
    case SDL_EVENT_TERMINATING :                                                // The application is being terminated by the OS.
    case SDL_EVENT_LOW_MEMORY :                                                 // The application is low on memory, free memory if possible.
    case SDL_EVENT_WILL_ENTER_BACKGROUND :                                      // The application is about to enter the background.
    case SDL_EVENT_DID_ENTER_BACKGROUND :                                       // The application did enter the background and may not get CPU for some time.
    case SDL_EVENT_WILL_ENTER_FOREGROUND :                                      // The application is about to enter the foreground.
    case SDL_EVENT_DID_ENTER_FOREGROUND :  break;                               // The application is now interactive.

    case SDL_EVENT_LOCALE_CHANGED :        {
      int          nLocales = 1;
      SDL_Locale **locales = SDL_GetPreferredLocales(&nLocales);
      if (locales == nullptr)
        SDL_Log("Warning: SDL_GetPreferredLocales(): %s\n", SDL_GetError());
      else {
        if (strcmp(locales[0]->language, "en") == 0) { }      // [ ]
        else if (strcmp(locales[0]->language, "fr") == 0) { } // [ ]
      // [ ] else ...
      }
      SDL_free(locales);
      break;
    }

    case SDL_EVENT_SYSTEM_THEME_CHANGED : // TODO: test if it works
      if (SDL_GetSystemTheme() == SDL_SYSTEM_THEME_LIGHT)
        ImGuiStyler::StyleColorsCustomLight();
      else
        ImGuiStyler::StyleColorsCustomDark();
      break;

    case SDL_EVENT_DISPLAY_ORIENTATION :
      switch (event->display.data1) {
        case SDL_ORIENTATION_LANDSCAPE :
        case SDL_ORIENTATION_LANDSCAPE_FLIPPED :
          break; // [ ] Horizontal screen
        default :
          break; // [ ] Vertical screen
      }
      break;

    case SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED : { // (most likely: DPI changed)
      float winScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
      if (winScale == 0.0f) {
        SDL_Log("Warning: SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay()): %s\n", SDL_GetError());
        winScale = 1.0f;
      }
      ImGuiStyle &style = ImGui::GetStyle();
      style.ScaleAllSizes(winScale);
      style.FontScaleDpi = winScale;
      break;
    }

    case SDL_EVENT_WINDOW_SHOWN :
    case SDL_EVENT_WINDOW_HIDDEN :
    case SDL_EVENT_WINDOW_EXPOSED :
    case SDL_EVENT_WINDOW_MOVED :

    case SDL_EVENT_WINDOW_RESIZED :
      app->resizeImGUI = true;
      break;

    case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED :
    case SDL_EVENT_WINDOW_METAL_VIEW_RESIZED :
    case SDL_EVENT_WINDOW_MINIMIZED :
    case SDL_EVENT_WINDOW_MAXIMIZED :
    case SDL_EVENT_WINDOW_RESTORED :
    case SDL_EVENT_WINDOW_MOUSE_ENTER :
    case SDL_EVENT_WINDOW_MOUSE_LEAVE :
    case SDL_EVENT_WINDOW_FOCUS_GAINED :
    case SDL_EVENT_WINDOW_FOCUS_LOST :
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED :
    case SDL_EVENT_WINDOW_HIT_TEST :
    case SDL_EVENT_WINDOW_ICCPROF_CHANGED :
    case SDL_EVENT_WINDOW_DISPLAY_CHANGED :
    case SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED :
    case SDL_EVENT_WINDOW_SAFE_AREA_CHANGED :
    case SDL_EVENT_WINDOW_OCCLUDED :
    case SDL_EVENT_WINDOW_ENTER_FULLSCREEN :
    case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN :
    case SDL_EVENT_WINDOW_DESTROYED :             break;

    case SDL_EVENT_KEY_DOWN :
      if (event->key.key == SDLK_ESCAPE) return SDL_APP_SUCCESS;
      break;
    // case SDL_EVENT_KEY_UP :
    // case SDL_EVENT_KEYBOARD_ADDED :
    // case SDL_EVENT_KEYBOARD_REMOVED :

    // case SDL_EVENT_MOUSE_MOTION :
    // case SDL_EVENT_MOUSE_BUTTON_DOWN :
    // case SDL_EVENT_MOUSE_BUTTON_UP :
    // case SDL_EVENT_MOUSE_WHEEL :
    // case SDL_EVENT_MOUSE_ADDED :
    // case SDL_EVENT_MOUSE_REMOVED :

    // TODO: probably no need since ImGui_ImplSDL3_ProcessEvent()
    // case SDL_EVENT_FINGER_DOWN :
    // case SDL_EVENT_FINGER_UP :
    // case SDL_EVENT_FINGER_MOTION :
    // case SDL_EVENT_FINGER_CANCELED :             break;

    case SDL_EVENT_CLIPBOARD_UPDATE :            break;

    case SDL_EVENT_AUDIO_DEVICE_ADDED :
    case SDL_EVENT_AUDIO_DEVICE_REMOVED :
    case SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED : break;

    case SDL_EVENT_SENSOR_UPDATE :               break;

    case SDL_EVENT_CAMERA_DEVICE_ADDED :
    case SDL_EVENT_CAMERA_DEVICE_REMOVED :
    case SDL_EVENT_CAMERA_DEVICE_APPROVED :
    case SDL_EVENT_CAMERA_DEVICE_DENIED :        break;

    case SDL_EVENT_RENDER_TARGETS_RESET :
    case SDL_EVENT_RENDER_DEVICE_RESET :
    case SDL_EVENT_RENDER_DEVICE_LOST :          break;
  }

  return SDL_APP_CONTINUE;
}
