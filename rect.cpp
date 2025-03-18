#include "rect.h"

Rectangle::Rectangle(){
	height = 10;
	width = 10;
	for(int i = 0; i < 4; i++){
		color[i] = 255;
	}
	*rect = {x, y, height, width};
}

Rectangle::Rectangle(int x, int y, int height, int width, int* color)
: GameObject(x, y){
	this->height = height;
	this->width = width;
	this->color = color;
	*rect = {x, y, height, width};
}

Rectangle::Rectangle(int x, int y, int height, int width, SDL_Renderer* renderer, int* color)
: GameObject(x, y, renderer){
	this->height = height;
	this->width = width;
	this->color = color;
	*rect = {x, y, height, width};
}

Rectangle::~Rectangle(){
	delete color;
	delete rect;
}

void Rectangle::draw(){
	*rect = {x, y, height, width};
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(renderer, rect);
}
