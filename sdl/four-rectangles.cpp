#include <SDL3/SDL.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("SDL3 Cross", 800, 600, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

  int size = 80;
  int cx = 400;
  int cy = 300;

  int gap = 30;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

  SDL_FRect rects[4] = {
      {cx - size / 2, cy - size * 1.5 - gap, size, size}, // top
      {cx - size * 1.5 - gap, cy - size / 2, size, size}, // left
      {cx + size / 2 + gap, cy - size / 2, size, size},   // right
      {cx - size / 2, cy + size / 2 + gap, size, size}    // bottom
  };

  for (int i = 0; i < 4; i++) {
    SDL_RenderFillRect(renderer, &rects[i]);
  }

  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
