#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>

class GameObject{
	protected:
		//Member variables
		int x, y, height, width; //Rectangle object associated with gameObject, used for collision and as target for loading image
		SDL_Rect* rect = new SDL_Rect{0, 0, 0, 0};
		
		SDL_Renderer* renderer = nullptr;
		char* imagePath = nullptr;

		//My grasp on surfaces and textures is weak, but youtube tutorials say this is how you load an object
		SDL_Surface* surf = nullptr;
		SDL_Texture* texture = nullptr;

		static std::vector<GameObject*> gameObjectList;

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
		
		//Functions
		void draw();
		void drawAll();
		void print();

};


#endif
