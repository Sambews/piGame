#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Spritesheet {
    private:
        SDL_FRect* clip;
        SDL_Texture* sheet;

    public:
        Spritesheet(std::string path, int cNum, int rNum){
            
        }
        SDL_FRect* getRect(){return clip;}
        void setRect(int x, int y){clip->x = x; clip->y = y;}

        void getTexture(){return sheet;}

};
#endif