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
<<<<<<< HEAD
        SDL_Surface* spritesheet = nullptr;
        SDL_Rect* imageSelect = nullptr;

    public:
        AnimatedObject(std::string, int, int);
        AnimatedObject(int, int, int, int, std::string, int, int);
=======
        SDL_Surface spritesheet = nullptr;
	SDL_Rect image = nullptr;
	int columnWidth;
	int rowWidth;	

    public:
        AnimatedObject(int, int, int, int, string, int, int);
>>>>>>> 312f728470405e7e775794f0e9cc90e89c81b598
        selectSprite(int, int);
	draw(SDL_Surface*, SDL_Rect*);

}


#endif
