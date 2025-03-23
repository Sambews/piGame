#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include "gameObject.h"
#include <vector>
#include <string>

struct location {
    int r;
    int c;
};

class AnimatedObject : public gameObject {
    private:
        vector<vector<location>> animations;
        SDL_Surface spritesheet = nullptr;
	SDL_Rect image = nullptr;
	int columnWidth;
	int rowWidth;	

    public:
        AnimatedObject(int, int, int, int, string, int, int);
        selectSprite(int, int);
	draw(SDL_Surface*, SDL_Rect*);

}


#endif
