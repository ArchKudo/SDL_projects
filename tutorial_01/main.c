#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "main.h"

int main(int argc, char const *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Cannot Initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  // man 3 atexit
  atexit(SDL_Quit);

  // SDL_Window creates a window with the specified position, dimensions, and
  // flags
  // Replaces SDL_SetVideoMode( https://goo.gl/lIoT1X )
  // More at: https://goo.gl/5KZkHn
  SDL_Window *window_1 =
      SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
  if (window_1 == NULL) {
    fprintf(stderr, "Couldn't create window: %s\n", SDL_GetError());
    exit(1);
  }

  while (1) {
  	get_input();
  	SDL_Delay(15);
  }
  return 0;
}
