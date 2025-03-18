//Hello world

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameObject.cpp"
#include "rect.cpp"


int main(){
	//Declaring SDL things
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Event e;
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	//Declaring variables
	bool running = true;

	SDL_CreateWindowAndRenderer(620, 620, 0, &window, &renderer);

	SDL_Rect* overlap = nullptr;
	
	SDL_ShowCursor(SDL_DISABLE);
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	int green[4] = {100, 255, 100, 255};
	int red[4] = {255, 100, 100, 255};
	int grey[4] = {100, 100, 100, 255};

	Rectangle fren(0, 00, 10, 10, renderer, green);
	Rectangle enemy(50, 50, 20, 20, renderer, red);
	Rectangle wall(300, 300, 30, 10, renderer, grey);

	GameObject door(150, 150, 32, 32, renderer, "./images/door.png");

	/*
	SDL_Surface* img = nullptr;
	img = IMG_Load("./images/door.png");
	SDL_Texture* image = SDL_CreateTextureFromSurface(renderer, img);
	*/

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
				}
			}
		}


		fren.setY(fren.getY() - (((keys[SDL_SCANCODE_W]*5) - (keys[SDL_SCANCODE_S]*5))));
		enemy.setY(enemy.getY() - ((keys[SDL_SCANCODE_UP]*5) - (keys[SDL_SCANCODE_DOWN]*5)));

		fren.setX(fren.getX() + ((keys[SDL_SCANCODE_D]*5) - (keys[SDL_SCANCODE_A]*5)));
		enemy.setX(enemy.getX() + ((keys[SDL_SCANCODE_RIGHT]*5) - (keys[SDL_SCANCODE_LEFT]*5)));
		
		bool intersection = SDL_IntersectRect(fren.getRect(), wall.getRect(), overlap);
		if(intersection){
			std::cout << "Intersection!!!" << '\n';
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		fren.draw();
		enemy.draw();
		wall.draw();
		door.draw();
		
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	//SDL_Quit();
	//IMG_Quit();
	return 0;
}
