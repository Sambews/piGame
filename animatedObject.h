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
        SDL_Surface* spritesheet = nullptr;
        SDL_Rect* imageSelect = nullptr;

    public:
        AnimatedObject(std::string, int, int);
        AnimatedObject(int, int, int, int, std::string, int, int);
        selectSprite(int, int);


}


#endif