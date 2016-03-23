// Opening a window

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "main.h"

int main(int argc, char const *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Cannot initialize SDL: %s",
                 SDL_GetError());
    return 3;
  }

  // man 3 atexit
  atexit(SDL_Quit);
  SDL_Window *window =
      SDL_CreateWindow("Displaying a window", POS, POS, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create a window: %s",
                 SDL_GetError());
    return 3;
  }
  // Replaces SDL_SetVideoMode( https://goo.gl/lIoT1X )
  // More at: https://goo.gl/5KZkHn

  while (1) {
    get_input();
    SDL_Delay(15);
  }
  return 0;
}
