#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "rect.h"


int main(){
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event e;
	SDL_Init(SDL_INIT_EVERYTHING);
	bool running = true;
	
	const int g = 1;
	int v = 0;
	int v2 = 0;
	bool gravity = false;

	SDL_Rect* overlap;

	SDL_CreateWindowAndRenderer(620, 620, 0, &window, &renderer);
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	int green[4] = {100, 255, 100, 255};
	int red[4] = {255, 100, 100, 255};
	int grey[4] = {100, 100, 100, 255};

	Rectangle fren(0, 00, 10, 10, renderer, green);
	Rectangle enemy(50, 50, 20, 20, renderer, red);
	Rectangle wall(300, 300, 30, 10, renderer, grey);
	
	while(running){
		SDL_PumpEvents();

		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				running = false;
			} else if (e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_ESCAPE:
						running = false;
						break;
					case SDLK_g:
						v = 0;
						gravity = !gravity;
						break;
					case SDLK_UP:
						if(gravity){
							v = -20;
						} 
						break;
					case SDLK_w:
						if(gravity){
							v2 = -20;
						}
						break;
					case SDLK_SPACE:
						v = 0;
						v2 = 0;
						break;
				}
			}
		}



		if(gravity){
			v += g;
			v2 += g;
		}
		if(!gravity){
			fren.setY(fren.getY() - (((keys[SDL_SCANCODE_W]*5) - (keys[SDL_SCANCODE_S]*5))));
			enemy.setY(enemy.getY() - ((keys[SDL_SCANCODE_UP]*5) - (keys[SDL_SCANCODE_DOWN]*5)));
		}

		fren.setX(fren.getX() + ((keys[SDL_SCANCODE_D]*5) - (keys[SDL_SCANCODE_A]*5)));
		enemy.setX(enemy.getX() + ((keys[SDL_SCANCODE_RIGHT]*5) - (keys[SDL_SCANCODE_LEFT]*5)));
		
		while(SDL_IntersectRect(fren.getRect(), wall.getRect(), overlap) && !gravity){
			fren.setX(fren.getX() + ((keys[SDL_SCANCODE_D]) - (keys[SDL_SCANCODE_A])));
			fren.setY(fren.getY() - (((keys[SDL_SCANCODE_W]) - (keys[SDL_SCANCODE_S]))));
		}
			

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		fren.draw();
		enemy.draw();
		wall.draw();

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	return 0;

}
