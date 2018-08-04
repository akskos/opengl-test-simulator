CPP_FILES = $(shell find src/ -name "*.cpp")
all:
	mkdir -p bin
	g++ -std=c++11 -o bin/simulator $(CPP_FILES) -lGL -lGLU -lGLEW -lSDL2 -lboost_program_options
