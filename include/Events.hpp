#pragma once

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_events.h"

SDL_AppResult processEvent(void *appstate, SDL_Event *event);
