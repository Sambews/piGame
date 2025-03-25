#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include "gameObject.h"
#include <vector>


struct location {
    int r;
    int c;
};

class AnimatedObject : public GameObject {
    private:
	std::vector<std::vector<location>> animations;
        SDL_Texture* spritesheet = nullptr;
        SDL_FRect* imageSelect = new SDL_FRect;
	SDL_FPoint sheetSize;

    public:
        AnimatedObject(int, int, int, int, std::string, int, int);
	~AnimatedObject();
        void selectSprite(int, int);
	void draw();
};


#endif
