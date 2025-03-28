#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <vector>
#include "spriteSheet.h"

class GameObject{
	protected:
		//Member variables
		SDL_FRect* rect = new SDL_FRect{0, 0, 16, 16};
		SDL_Renderer* renderer = nullptr;

		//My grasp on surfaces and textures is weak, but youtube tutorials say this is how you load an object
		SDL_Texture* texture = nullptr;
		static std::vector<GameObject*> gameObjectList;

	public:
		//Constructors
		GameObject();
		GameObject(int, int, int, int);
		GameObject(int, int, int, int, SDL_Renderer*);
		GameObject(int, int, int, int, SDL_Renderer*, std::string);
		~GameObject();

		//Mutators and accessors
		int getX(){return rect->x;}
		void setX(int x){rect->x = x;}

		int getY(){return rect->y;}
		void setY(int y){rect->y = y;}
		
		int getWidth(){return rect->w;}
		void setWidth(int w){rect->w = w;}

		int getHeight(){return rect->h;}
		void setHeight(int h){rect->h = h;}

		SDL_Renderer* getRenderer(){return renderer;}
		void setRenderer(SDL_Renderer* r){renderer = r;}
		
		SDL_Texture* getTexture(){return texture;}

		SDL_FRect* getRect(){return rect;}
		
		//Functions
		void draw();
		static void drawAll();
		void setSprite(Spritesheet*, int, int);
		void print();
};


#endif
