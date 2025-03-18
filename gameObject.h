#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL2/SDL.h>

class GameObject{
	protected:
		int x, y;
		SDL_Renderer* renderer;
	
	public:
		//Constructors
		GameObject(){x = 0; y = 0;}
		GameObject(int x, int y){this->x = x; this->y = y;}
		GameObject(int x, int y, SDL_Renderer* r){this->x = x; this->y = y; renderer = r;}
		~GameObject(){}

		//Mutators and accessors
		int getX(){return x;}
		void setX(int x){this->x = x;}

		int getY(){return y;}
		void setY(int y){this->y = y;}

		SDL_Renderer* getRenderer(){return renderer;}
		void setRenderer(SDL_Renderer* r){renderer = r;}
};


#endif
