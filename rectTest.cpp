#include <SDL2/SDL.h>
#include "rect.cpp"

int main(){
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);
	
	Rectangle rect;
	rect.setRenderer(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	rect.draw();
	SDL_Delay(1000);

	return 0;
}

