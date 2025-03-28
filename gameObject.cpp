#include "gameObject.h"

//Constructors

GameObject::GameObject(){
	GameObject::gameObjectList.push_back(this);
}

GameObject::GameObject(int x, int y, int width, int height){
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
	GameObject::gameObjectList.push_back(this);
}


GameObject::GameObject(int x, int y, int width, int height, SDL_Renderer* r){
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
	renderer = r;
	GameObject::gameObjectList.push_back(this);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_TARGET, rect->w, rect->h);
}


GameObject::GameObject(int x, int y, int width, int height, SDL_Renderer* r, std::string path){
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
	renderer = r;
	GameObject::gameObjectList.push_back(this);
}
//Destructor
GameObject::~GameObject(){
	SDL_DestroyTexture(texture);
}

//Functions
void GameObject::draw(){
	std::cout << rect->w << ", " << rect->h << '\n';
	SDL_RenderTexture(renderer, texture, NULL, rect);
}

void GameObject::drawAll(){
	for(GameObject* g : GameObject::gameObjectList){
		g->draw();
	}
}

void GameObject::setSprite(Spritesheet* sheet, int x, int y){
	int newX = sheet->getRect()->w * x;
	int newY = sheet->getRect()->h * y;
	sheet->setRect(newX, newY);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderTexture(renderer, sheet->getTexture(), sheet->getRect(), NULL);
	SDL_SetRenderTarget(renderer, NULL);
	std::cout << "Changed sprite" << '\n';
}
