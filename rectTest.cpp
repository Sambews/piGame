#include <SDL2/SDL.h>
#include "rect.cpp"

int main(){
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event e;
	SDL_Init(SDL_INIT_TIMER);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer);

	int blue[4] = {100, 100, 255, 255};
	Rectangle rect(0, 0, 50, 50, renderer, blue);

	bool running = true;
	while(running){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_KEYDOWN){
				if(e.key.keysym.sym){
					running = false;
					SDL_QuitSubSystem(SDL_INIT_TIMER);
					SDL_QuitSubSystem(SDL_INIT_VIDEO);
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		rect.draw();

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	return 0;
}

