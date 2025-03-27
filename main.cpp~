//Native(?) c++ libraries
#include <iostream>
#include <string>
#include <vector>
//Third party
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
//Includes
#include "gameObject.cpp"
#include "rect.cpp"
#include "animatedObject.cpp"

//Macros
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

#define STANDING 2
#define WALKING 1

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
	SDL_Init(SDL_INIT_VIDEO);
	SDL_HideCursor();
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer("Text.txt", WINDOWWIDTH, WINDOWHEIGHT, 0, &window, &renderer);
	SDL_Event e;
	const bool* keys = SDL_GetKeyboardState(NULL);


	//Creating objects
	std::vector<GameObject*> solidObjects;
	GameObject wall(300, 300, 32, 32, renderer, "./images/wallBaseUR.png");
	solidObjects.push_back(&wall);

	AnimatedObject MC(150, 150, 38, 58, renderer, "./images/dressCharacterSpriteSheet.png", 4, 8);
	MC.setOrientation(RIGHT);
	MC.setState(STANDING);
	MC.selectSprite(0, 0);
	MC.createAnimation(1, 0);
	MC.createAnimation(1, 1);
	MC.createAnimation(7, 2);
	MC.createAnimation(7, 3);


	int frameCount2 = 0;
	int walkCount = 1;
	bool right = true;
	std::string walkImg = "./images/dressCharacterWalk1.png";


	//Main game loop
	while(running){
		SDL_PumpEvents();
		
		//Event handler
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_EVENT_QUIT){
				running = false;
			} 
			else if (e.type == SDL_EVENT_KEY_DOWN){ //Checking key presses
				switch(e.key.key){
					case SDLK_ESCAPE:
						running = false;
						break;
					case SDLK_SPACE:
						std::cout << "Hello world!" << '\n';
						break;
				}
			}
		}

		//Calculating up/left/down/right inputs from WASD keys
		int xInput = (keys[SDL_SCANCODE_D] - keys[SDL_SCANCODE_A]) * PLAYERSPEED;
		int yInput = (keys[SDL_SCANCODE_S] - keys[SDL_SCANCODE_W]) * PLAYERSPEED;


		//Sets the orientation of the character
		if(xInput > 0){
			MC.setOrientation(RIGHT);
		} else if(xInput < 0){
			MC.setOrientation(LEFT);
		}


		//Checks to see if the character is walking or standing still
		if((xInput != 0) && (MC.getState() == STANDING)){
			MC.setState(WALKING);
			switch(MC.getOrientation()){
				case RIGHT:
					MC.setAnimation(2, 5);
					break;
				case LEFT:
					MC.setAnimation(3, 5);
					break;
			}			
		}
		else if((xInput == 0) && (MC.getState() == WALKING)){
			MC.setState(STANDING);
			switch(MC.getOrientation()){
				case RIGHT:
					MC.setAnimation(0, 30);
					break;
				case LEFT:
					MC.setAnimation(1, 30);
					break;
			}
		}


		//Update MC's position, with added collision detection
		MC.setY(MC.getY() + yInput);
		for(GameObject* g : solidObjects){
			while(SDL_HasRectIntersectionFloat(MC.getRect(), g->getRect())){
				MC.setY(MC.getY() - (yInput / PLAYERSPEED));
			}
		}
		MC.setX(MC.getX() + xInput);
		for(GameObject* g : solidObjects){
			while(SDL_HasRectIntersectionFloat(MC.getRect(), g->getRect())){
				MC.setX(MC.getX() - (xInput / PLAYERSPEED));
			}
		}
		
		//Fill the screen with black
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	
		//Draw the various objects to the screen
		MC.updateAnimation();	
		MC.draw();
		GameObject::drawAll();

		//Displays the renderer, delays 16 milliseconds for 60 fps
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}

	return 0;
}
