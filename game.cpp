#include "SDL.h"
#include "global.h"
#include "game.h"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
void GameState::StartGame(SDLAPP* _app) {
  app = _app;
}

void GameState::Render() {
  SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
  SDL_RenderClear(app->renderer);

  // Draw

  SDL_RenderPresent(app->renderer);
}

void GameState::Update() {

  // Clear Buttons
  for (int b = NOOF_BUTTONS - 1; b >= 0; --b) {
    buttonMap[b] &= 1;
  }
}


void GameState::GameEvent(SDL_Event* evt) {
  switch (evt->type) {
  case SDL_KEYDOWN:
    switch (evt->key.keysym.scancode) {
    case SDL_SCANCODE_UP:
      buttonMap[B_UP] = 3;
      break;
    case SDL_SCANCODE_DOWN:
      buttonMap[B_DOWN] = 3;
      break;
    case SDL_SCANCODE_LEFT:
      buttonMap[B_LEFT] = 3;
      break;
    case SDL_SCANCODE_RIGHT:
      buttonMap[B_RIGHT] = 3;
      break;

    case SDL_SCANCODE_I:
      buttonMap[B_CAMUP] = 3;
      break;
    case SDL_SCANCODE_K:
      buttonMap[B_CAMDOWN] = 3;
      break;
    case SDL_SCANCODE_J:
      buttonMap[B_CAMLEFT] = 3;
      break;
    case SDL_SCANCODE_L:
      buttonMap[B_CAMRIGHT] = 3;
      break;
    }
    break;

  case SDL_KEYUP:
    switch (evt->key.keysym.scancode) {
    case SDL_SCANCODE_UP:
      buttonMap[B_UP] = 0;
      break;
    case SDL_SCANCODE_DOWN:
      buttonMap[B_DOWN] = 0;
      break;
    case SDL_SCANCODE_LEFT:
      buttonMap[B_LEFT] = 0;
      break;
    case SDL_SCANCODE_RIGHT:
      buttonMap[B_RIGHT] = 0;
      break;

    case SDL_SCANCODE_I:
      buttonMap[B_CAMUP] = 0;
      break;
    case SDL_SCANCODE_K:
      buttonMap[B_CAMDOWN] = 0;
      break;
    case SDL_SCANCODE_J:
      buttonMap[B_CAMLEFT] = 0;
      break;
    case SDL_SCANCODE_L:
      buttonMap[B_CAMRIGHT] = 0;
      break;
    }
    break;

  case SDL_MOUSEMOTION:
    break;
  case SDL_MOUSEBUTTONDOWN:
  case SDL_MOUSEBUTTONUP:
    break;
  case SDL_MOUSEWHEEL:
    break;
  }
}

//