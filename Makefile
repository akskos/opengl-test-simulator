all:
	mkdir -p bin
	g++ -std=c++11 -o bin/test src/*.cpp -lGL -lGLU -lGLEW -lSDL2
