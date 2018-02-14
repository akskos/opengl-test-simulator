all:
	g++ -std=c++11 -o bin/test src/*.cpp -lGL -lGLU -lGLEW -lglfw
	./bin/test
