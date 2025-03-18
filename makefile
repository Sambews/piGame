test: test.cpp rect.cpp rect.h
	g++ gameObject.h rect.cpp test.cpp -lSDL2 -o test
rectTest: rectTest.cpp rect.h rect.cpp
	g++ gameObject.h rect.cpp rectTest.cpp -lSDL2 -o rectTest
