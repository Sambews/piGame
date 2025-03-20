main: main.cpp rect.cpp rect.h gameObject.h
	g++ main.cpp -lSDL2 -lSDL2_image -o prog
	cp main.cpp main.cpp~
	./prog
rectTest: rectTest.cpp rect.h rect.cpp
	g++ rectTest.cpp -lSDL2 -o rectTest
