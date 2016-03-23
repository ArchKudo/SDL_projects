// Create a red window

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "main.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;

int main(int argc, char const *argv[]) {

  if (SDL_Init((SDL_INIT_EVERYTHING))) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Cannot initialize SDL: %s\n",
                 SDL_GetError());
    return 3;
  }
  atexit(SDL_Quit);

  if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window,
                                  &renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't create window and renderer: %s", SDL_GetError());
    return 3;
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_Delay(4000);
  return 0;
}
