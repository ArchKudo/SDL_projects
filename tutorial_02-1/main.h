#pragma once

#define HEIGHT 480
#define WIDTH 640
#define POS SDL_WINDOWPOS_UNDEFINED
#define RED 255, 0, 0, 255
#define BLUE 0, 0, 255, 0

#define RECT_POS_X 240
#define RECT_POS_Y 320
#define RECT_WIDTH 50
#define RECT_HEIGHT 50

extern SDL_Window *window;
extern SDL_Texture *texture;
extern SDL_Renderer *renderer;
extern SDL_Rect rectangle;
