#include "animatedObject.h"
#include <iostream>

AnimatedObject::AnimatedObject(int x, int y, int width, int height, SDL_Renderer* r, std::string path, int rNum, int cNum)
: GameObject(x, y, width, height, renderer){
	crying = IMG_Load(&path[0]);
	spritesheet = SDL_CreateTextureFromSurface(renderer, crying);   
	if(spritesheet == NULL){
		std::cout << "Couldn't create surface" << '\n';
		std::cout << SDL_GetError() << '\n';
	}
	SDL_GetTextureSize(spritesheet, &sheetSize.x, &sheetSize.y);
	imageSelect->w = sheetSize.x / cNum;
	imageSelect->h = sheetSize.y / rNum;
}

AnimatedObject::~AnimatedObject(){
    SDL_DestroyTexture(spritesheet);
}

void AnimatedObject::selectSprite(int x, int y){
	imageSelect->x = x * imageSelect->w;
	imageSelect->y = y * imageSelect->y;
	//SDL_BlitSurface(spritesheet, imageSelect, surf, NULL);
}

void AnimatedObject::draw(){
	SDL_RenderTexture(renderer, spritesheet, imageSelect, rect);
}

void AnimatedObject::print(){
	std::cout << "Size: " << sheetSize.x << ", " << sheetSize.y << '\n';
}
