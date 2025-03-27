#include "animatedObject.h"
#include <iostream>

AnimatedObject::AnimatedObject(int x, int y, int width, int height, SDL_Renderer* r, std::string path, int rNum, int cNum)
: GameObject(x, y, width, height, r){
	crying = IMG_Load(&path[0]);
	spritesheet = SDL_CreateTextureFromSurface(renderer, crying);   
	
	if(!spritesheet){
		std::cout << "Couldn't create spritesheet" << '\n';
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

void AnimatedObject::createAnimation(int x, int y){
	LinkedList<location> list;
	animationList.push_back(list);
	for(int i = 0; i <= x; i++){
		location l;
		l.c = i;
		l.r = y;
		animationList.back().add(l);
	}
}


//Speed = number of frames spent on each frame
void AnimatedObject::setAnimation(int animationIndex, int speed){
	animationFrame = animationList.at(animationIndex).getHead();
	frameCounter = 0;
	animationSpeed = speed;
}

bool AnimatedObject::updateAnimation(){
	if(!animationFrame){
		return false;
	}
	if(frameCounter != animationSpeed){
		frameCounter++;
		return false;
	} else {
		frameCounter = 0;
		animationFrame = animationFrame->next;
		selectSprite(animationFrame->val.c, animationFrame->val.r);
		return true;
	}
}

void AnimatedObject::printAnimations(){
	for(LinkedList<location> list : animationList){
		Node<location>* ptr = list.getHead();

		std::cout << ptr->val.c << ',' << ptr->val.r << ' ';
		ptr = ptr->next;

		while(ptr != list.getHead()){
			std::cout << ptr->val.c << ',' << ptr->val.r << ' ';
			ptr = ptr->next;
		}

		std::cout << '\n';
	}
}
