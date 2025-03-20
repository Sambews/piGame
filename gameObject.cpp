#include "gameObject.h"

//Constructors

GameObject::GameObject(){
	x = 0;
	y = 0;
	width = 10;
	height = 10;
	GameObject::gameObjectList.push_back(this);
}

GameObject::GameObject(int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	GameObject::gameObjectList.push_back(this);
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
	GameObject::gameObjectList.push_back(this);
}
//Destructor
GameObject::~GameObject(){
	//35% certain things break if we remove this. Worth testing at some point
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surf);
}

//Functions

//Update the image path and image.
//Image path may not need to exist. When loading image, maybe automatically append "./images/" and concat ".png" to simplify input?
void GameObject::setImage(std::string path){
	imagePath = &path[0];
	surf = IMG_Load(imagePath);
	updateTexture();
}

//Draw function updates the rectangle position and loads the texture
void GameObject::draw(){
	*rect = {x, y, width, height};
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

void GameObject::drawAll(){
	for(GameObject* g : GameObject::gameObjectList){
		g->draw();
	}
}
