#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle {
private:
	int x, y, height, width;
	SDL_Rect* rect = new SDL_Rect;
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

	SDL_Rect* getRect(){return rect;}

	//Member functions
	void draw();
};
#endif
