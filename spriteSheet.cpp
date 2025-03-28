#include "spriteSheet.h"

Spritesheet::Spritesheet(std::string path, int cNum, int rNum, SDL_Renderer* r){
	SDL_Surface* surf = IMG_Load(&path[0]);
	sheet = SDL_CreateTextureFromSurface(r, surf);
	if(!sheet){
		std::cout << "Couldn't create spritesheet texture" << '\n';
		std::cout << SDL_GetError() << '\n';
	}
	clip = new SDL_FRect{0, 0, (sheet->w / cNum), (sheet->h / rNum)};
}
