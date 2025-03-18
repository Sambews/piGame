#include "rect.h"
#include <iostream>

Rectangle::Rectangle(){
	height = 10;
	width = 10;
	for(int i = 0; i < 4; i++){
		color[i] = 255;
	}
	*rect = {x, y, height, width};
}

Rectangle::Rectangle(int x, int y, int height, int width, int* color){
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->color = color;
	*rect = {x, y, height, width};
}

Rectangle::Rectangle(int x, int y, int height, int width, SDL_Renderer* renderer, int* color){
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	this->color = color;
	this->renderer = renderer;
	*rect = {x, y, height, width};
}

Rectangle::~Rectangle(){
	delete rect;	
}

void Rectangle::draw(){
	*rect = {x, y, height, width};
	
	/*
	std::cout << x << '\n' << y << '\n' << height << '\n' << width << '\n';
	for(int i = 0; i < 4; i++){
		std::cout << color[i] << '\n';
	}
	*/

	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	SDL_RenderFillRect(renderer, rect);
}
