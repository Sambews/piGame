#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include "gameObject.h"
#include "Utilities/linkedList.cpp"
#include <vector>


struct location {
    int r;
    int c;
};

class AnimatedObject : public GameObject {
    private:
	std::vector<LinkedList<location>> animationList;
        SDL_Texture* spritesheet = nullptr;
	SDL_Surface* crying = nullptr;
        SDL_FRect* imageSelect = new SDL_FRect;
	SDL_FPoint sheetSize;
	
	int frameCounter;
	int animationSpeed;
	Node<location>* animationFrame;
	int state;
	int orientation;

    public:
        AnimatedObject(int, int, int, int, SDL_Renderer*, std::string, int, int);
	~AnimatedObject();

	int getFrameCounter(){return frameCounter;}
	void setFrameCounter(int n){frameCounter = n;}

	int getAnimationSpeed(){return animationSpeed;}
	void setAnimationSpeed(int n){animationSpeed = n;}

	int getState(){return state;}
	void setState(int n){state = n;}

	int getOrientation(){return orientation;}
	void setOrientation(int n){orientation = n;}

        void selectSprite(int, int);
	void draw();
	void print();
	void createAnimation(int, int);
	void printAnimations();
	void setAnimation(int, int);
	bool updateAnimation();
};


#endif
