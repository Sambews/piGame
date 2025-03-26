#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL3/SDL.h>


//This class isn't going to be useful, since rect objects are built into the gameObject class. This is just for testing things. 

class Rectangle {
private:
	int x, y, height, width;
	SDL_FRect* rect = new SDL_FRect;
	SDL_Renderer* renderer;
	int* color = new int;

public:
	//Constructors and destructors
	Rectangle();
	Rectangle(int, int, int, int, int*);
	Rectangle(int, int, int, int, SDL_Renderer*, int*);
	~Rectangle();

	//Mutators and accessors 
	int getX(){return x;}
	void setX(int n){x = n;}
	
	int getY(){return y;}
	void setY(int n){y = n;}

	int getHeight(){return height;}
	void setHeight(int n){height = n;}

	int getWidth(){return width;}
	void setWidth(int n){width = n;}

	SDL_Renderer* getRenderer(){return renderer;}
	void setRenderer(SDL_Renderer* r){renderer = r;}

	int* getColor(){return color;}
	void setColor(int* c){color = c;}

	SDL_FRect* getRect(){return rect;}

	//Member functions
	void draw();
};
#endif
