#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <iostream>

class Spritesheet {
    private:
        SDL_FRect* clip = nullptr;
        SDL_Texture* sheet = nullptr;

    public:
        Spritesheet(std::string, int, int, SDL_Renderer*);
	~Spritesheet(){delete clip;}
        SDL_FRect* getRect(){return clip;}
        void setRect(int x, int y){clip->x = x; clip->y = y;}

        SDL_Texture* getTexture(){return sheet;}
	
	void draw();
};
#endif
