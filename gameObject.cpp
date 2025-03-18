#include "gameObject.h"

GameObject::GameObject(){
	x = 0;
	y = 0;
	width = 10;
	height = 10;
}

GameObject::GameObject(int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

GameObject::GameObject(int x, int y, int width, int height, SDL_Renderer* r, std::string path){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	renderer = r;
	imagePath = &path[0];
	surf = IMG_Load(imagePath);
	texture = SDL_CreateTextureFromSurface(renderer, surf);
}

GameObject::~GameObject(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
}

void GameObject::setImage(char* path){
	imagePath = path;
	surf = IMG_Load(path);
	updateTexture();
}

void GameObject::draw(){
	*rect = {x, y, width, height};
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_RenderCopy(renderer, texture, NULL, rect);
}
