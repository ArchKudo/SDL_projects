// Display an image on the enire screen

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "main.h"

SDL_Window *window = NULL;
SDL_Surface *image = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;

int main(int argc, char const *argv[]) {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Cannot initialize SDL: %s",
                 SDL_GetError());
    return 3;
  }
  IMG_Init(IMG_INIT_JPG);
  window = SDL_CreateWindow("Displaying an image", POS, POS, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create a window: %s",
                 SDL_GetError());
    return 3;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Could not create a renderer: %s",
                 SDL_GetError());
    return 3;
  }
  SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);
  SDL_RenderClear(renderer);
  image = IMG_Load("dexter.jpg");
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  while (1) {
    get_input();
    SDL_Delay(16);
  }
  atexit(cleanup);
  return 0;
}

void cleanup(void) {
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  IMG_Quit();
  SDL_Quit();
}
