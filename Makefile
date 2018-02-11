all:
	g++ -o bin/test src/*.cpp -lGL -lGLU -lGLEW -lglfw
	./bin/test
