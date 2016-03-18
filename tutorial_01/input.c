#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "main.h"

void get_input(void) {
  // SDL_Event: A union that contains structures for the different event types.
  // More at: https://goo.gl/jpdKDL
  SDL_Event event;

  // SDL_PollEvent: Use this function to poll for currently pending events.
  // More at: https://goo.gl/CHZGSq
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      exit(0);
      break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        exit(0);
        break;
      }
      break;

    default:
      break;
    }
  }
}
