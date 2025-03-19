//Hello world

//Native(?) c++ libraries
#include <iostream>
#include <string>
//Third party
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//Includes
#include "gameObject.cpp"
#include "rect.cpp"


int main(){
	//Declaring variables. It's a common practice to name constant variables in all caps
	bool running = true;
	const int WINDOWWIDTH = 1080;
	const int WINDOWHEIGHT = 720;
	const int PLAYERSPEED = 5;
	int red[4] = {255, 100, 100, 255};
	int green[4] = {100, 255, 100, 255};
	int blue[4] = {100, 100, 255, 255};
	int grey[4] = {100, 100, 100, 255};
	
	//Declaring SDL things
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	SDL_ShowCursor(SDL_DISABLE);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(WINDOWWIDTH, WINDOWHEIGHT, 0, &window, &renderer);
	SDL_Event e;
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	//Declaring variables

	//Creating objects
	Rectangle enemy(50, 50, 20, 20, renderer, red);
	Rectangle wall(300, 300, 30, 10, renderer, grey);
	GameObject MC(150, 150, 32, 32, renderer, "./images/dressCharacter.png");

	//Main game loop
	while(running){
		SDL_PumpEvents();
		
		//Event handler
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				running = false;
			} else if (e.type == SDL_KEYDOWN){ //Checking key presses
				switch(e.key.keysym.sym){
					case SDLK_ESCAPE:
						running = false;
						break;
				}
			}
		}

		//Calculating up/left/down/right inputs from WASD keys
		int xInput = (keys[SDL_SCANCODE_D] - keys[SDL_SCANCODE_A]) * PLAYERSPEED;
		int yInput = (keys[SDL_SCANCODE_S] - keys[SDL_SCANCODE_W]) * PLAYERSPEED;

		//Turns character left and right
		if(xInput > 0){
			MC.setImage("./images/dressCharacter.png");
		}
		if(xInput < 0){
			MC.setImage("./images/dressCharacterL.png");
		}
	
		//Update MC's position
		MC.setY(MC.getY() + yInput);
		MC.setX(MC.getX() + xInput);
		
		//Update the red rectangle's position based off of arrow keys
		enemy.setY(enemy.getY() - ((keys[SDL_SCANCODE_UP]*5) - (keys[SDL_SCANCODE_DOWN]*5)));
		enemy.setX(enemy.getX() + ((keys[SDL_SCANCODE_RIGHT]*5) - (keys[SDL_SCANCODE_LEFT]*5)));
		
		//Fill the screen with black
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	
		//Draw the various objects to the screen
		enemy.draw();
		wall.draw();
		MC.draw();
	
		//Displays the renderer, delays 16 milliseconds for 60 fps
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	return 0;
}
