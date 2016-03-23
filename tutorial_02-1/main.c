//Create a blue rectangle in red background

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "main.h"
int main(int argc, char const *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Cannot initialize SDL: %s",
                 SDL_GetError());
    return 3;
  }
  SDL_Window *window =
      SDL_CreateWindow("Displaying a rectangle", POS, POS, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create a window: %s",
                 SDL_GetError());
    return 3;
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Could not create a renderer: %s",
                 SDL_GetError());
    return 3;
  }
  SDL_SetRenderDrawColor(renderer, RED);
  SDL_RenderClear(renderer);
  SDL_Rect rectangle = {RECT_POS_X, RECT_POS_Y, RECT_WIDTH, RECT_HEIGHT};
  SDL_SetRenderDrawColor(renderer, BLUE);
  SDL_RenderFillRect(renderer, &rectangle);
  SDL_RenderDrawRect(renderer, &rectangle);
  SDL_RenderPresent(renderer);
  SDL_Delay(4000);
  return 0;
}
