//Native(?) c++ libraries
#include <iostream>
#include <string>
#include <vector>
//Third party
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//Includes
#include "gameObject.cpp"
#include "rect.cpp"

//Static member of the GameObject class
std::vector<GameObject*> GameObject::gameObjectList;

int main(){
	//Declaring variables
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


	//Creating objects
	std::vector<GameObject*> solidObjects;
	Rectangle enemy(50, 50, 20, 20, renderer, red);
	GameObject MC(150, 150, 38, 58, renderer, "./images/dressCharacter.png");
	GameObject wall(300, 300, 32, 32, renderer, "./images/wallBaseUR.png");
	solidObjects.push_back(&wall);


	int frameCount = 0;
	int walkCount = 1;
	bool right = true;
	std::string walkImg = "./images/dressCharacterWalk1.png";


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
		if(xInput == 0){
			frameCount = 0;
			walkCount = 1;
			if(right){
				MC.setImage("./images/dressCharacter.png");
			} else {
				MC.setImage("./images/dressCharacterL.png");
			}
		} else if(xInput > 0){
			
			if(frameCount == 7){
				std::cout << "Frame count has looped. Walk count is " << walkCount << std::endl;
				frameCount = 0;
				
				if(walkCount == 8){
					walkCount = 1;
				} else {
					walkCount++;
				}
				walkImg = "./images/dressCharacterWalk" + std::to_string(walkCount) + ".png";
				MC.setImage(walkImg);
			} else {frameCount++;}
		}



	
		//Update MC's position, with added collision detection
		MC.setY(MC.getY() + yInput);
		for(GameObject* g : solidObjects){
			while(SDL_HasIntersection(MC.getRect(), g->getRect())){
				MC.setY(MC.getY() - (yInput / PLAYERSPEED));
			}
		}
		MC.setX(MC.getX() + xInput);
		for(GameObject* g : solidObjects){
			while(SDL_HasIntersection(MC.getRect(), g->getRect())){
				MC.setX(MC.getX() - (xInput / PLAYERSPEED));
			}
		}
		

		//Update the red rectangle's position based off of arrow keys
		enemy.setY(enemy.getY() - ((keys[SDL_SCANCODE_UP]*5) - (keys[SDL_SCANCODE_DOWN]*5)));
		enemy.setX(enemy.getX() + ((keys[SDL_SCANCODE_RIGHT]*5) - (keys[SDL_SCANCODE_LEFT]*5)));
	
		//Fill the screen with black
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	
		//Draw the various objects to the screen
	
		GameObject::drawAll();

		enemy.draw();

		//Displays the renderer, delays 16 milliseconds for 60 fps
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	return 0;
}
