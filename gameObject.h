#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class GameObject{
	protected:
		int x, y, height, width;
		SDL_Renderer* renderer = nullptr;
		char* imagePath = nullptr;
		SDL_Rect* rect = new SDL_Rect{0, 0, 0, 0};
		SDL_Surface* surf = nullptr;
		SDL_Texture* texture = nullptr;

	public:
		//Constructors
		GameObject();
		GameObject(int, int, int, int);
		GameObject(int, int, int, int, SDL_Renderer*, std::string);
		~GameObject();

		//Mutators and accessors
		int getX(){return x;}
		void setX(int x){this->x = x;}

		int getY(){return y;}
		void setY(int y){this->y = y;}

		char* getImage(){return imagePath;}
		void setImage(std::string);

		SDL_Renderer* getRenderer(){return renderer;}
		void setRenderer(SDL_Renderer* r){renderer = r;}

		SDL_Texture* getTexture(){return texture;}
		void updateTexture(){texture = SDL_CreateTextureFromSurface(renderer, surf);}

		SDL_Rect* getRect(){return rect;}
		
		void draw();
		void print();

};


#endif
