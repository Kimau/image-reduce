#pragma once

enum Buttons {
  B_UP, B_DOWN, B_LEFT, B_RIGHT,
  B_CAMUP, B_CAMDOWN, B_CAMLEFT, B_CAMRIGHT, NOOF_BUTTONS
};
struct SDLAPP;

class GameState {
  int buttonMap[NOOF_BUTTONS];

  SDLAPP *app;

  // Textures

  // Camera

  // Player
  
public:
  void StartGame(SDLAPP *_app);
  void Render();
  void Update();
  void GameEvent(SDL_Event *evt);
};
