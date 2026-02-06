//
// Created by Иван Насекин on 06.02.2026.
//
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

bool isRunning = false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool initWindow(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_BORDERLESS);

  if (!window) {
    fprintf(stderr, "Window could not be created! SDL Error: %s\n", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    fprintf(stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
  }

  return true;
}

void setup(void) {

}

void processInput(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) {
        isRunning = false;
      }
      break;
  }
}

void update(void) {

}

void render(void) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);
}

int main(void) {
  isRunning = initWindow();

  setup();

  while (isRunning) {
    processInput();
    update();
    render();
  }

  return 0;
}