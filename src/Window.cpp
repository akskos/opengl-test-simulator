#include "Window.h"

using namespace std;
typedef Window::Builder Builder;

Window::Window():
window(nullptr)
{}

Window::Window(SDL_Window* window, SDL_GLContext& context):
window(window),
context(context)
{}

void Window::close() {
    SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::render() {
    SDL_GL_SwapWindow(window);
}

Builder::Builder():
title("title"),
size(512)
{}

Window Builder::build() {
    // Init
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create window
    SDL_Window* window = SDL_CreateWindow(
	    title.c_str(),
	    SDL_WINDOWPOS_CENTERED,
	    SDL_WINDOWPOS_CENTERED,
	    size,
	    size,
	    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    SDL_GLContext context = SDL_GL_CreateContext(window);

    // Set some options
    SDL_GL_SetSwapInterval(1);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    return Window(window, context);
}

Builder& Builder::setTitle(string title) {
    this->title = title;
    return *this;
}

Builder& Builder::setSize(int size) {
    this->size = size;
    return *this;
}