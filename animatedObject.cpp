#include "animatedObject.h"

AnimatedObject::AnimatedObject(std::string path, int rNum, int cNum){
    spritesheet = load_png(path);
    
    imageSelect->w = spritesheet->w / cNum;
    imageSelect->h = spritesheet->h / rNum;
}

AnimatedObject::AnimatedObject(int x, int y, int width, int height, std::string path, int rNum, int cNum)
: GameObject(x, y, width, height){
    spritesheet = load_png(path);
    
    imageSelect->w = spritesheet->w / cNum;
    imageSelect->h = spritesheet->h / rNum;
}

AnimatedObject::~AnimatedObject(){
    SDL_FreeSurface(spritesheet);
}

void AnimatedObject::selectSprite(int x, int y){
    imageSelect->x = x * imageSelect->w;
    imageSelect->y = y * imageSelect->y;

    SDL_BlitSurface(spritesheet, imageSelect, surf, NULL);
}