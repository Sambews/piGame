main: main.cpp rect.cpp rect.h gameObject.h
	g++ main.cpp -o prog `pkg-config --libs --cflags sdl3` `pkg-config --libs --cflags sdl3-image` 
	cp main.cpp main.cpp~
	./prog
rectTest: rectTest.cpp rect.h rect.cpp
	g++ rectTest.cpp -lSDL2 -o rectTest
