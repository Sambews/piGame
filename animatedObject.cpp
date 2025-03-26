#include "animatedObject.h"
#include <iostream>

AnimatedObject::AnimatedObject(int x, int y, int width, int height, SDL_Renderer* r, std::string path, int rNum, int cNum)
: GameObject(x, y, width, height, r){
	crying = IMG_Load(&path[0]);
	spritesheet = SDL_CreateTextureFromSurface(renderer, crying);   
	if(spritesheet == NULL){
		std::cout << "Couldn't create surface" << '\n';
		std::cout << SDL_GetError() << '\n';
	}
	SDL_GetTextureSize(spritesheet, &sheetSize.x, &sheetSize.y);
	imageSelect->w = sheetSize.x / cNum;
	imageSelect->h = sheetSize.y / rNum;
	//std::cout << "Width, height: " << imageSelect->w << ", " << imageSelect->h << '\n';
}

AnimatedObject::~AnimatedObject(){
    SDL_DestroyTexture(spritesheet);
}

void AnimatedObject::selectSprite(int x, int y){
	imageSelect->x = x * imageSelect->w;
	imageSelect->y = y * imageSelect->h;
	//std::cout << "New x: " << imageSelect->x << '\n';
	//std::cout << "New y: " << imageSelect->y << '\n';
}

void AnimatedObject::draw(){
	SDL_RenderTexture(renderer, spritesheet, imageSelect, rect);
}

void AnimatedObject::print(){
	std::cout << "Size: " << sheetSize.x << ", " << sheetSize.y << '\n';
}
