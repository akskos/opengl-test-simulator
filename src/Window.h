#ifndef _WINDOW_H
#define _WINDOW_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window();
    Window(SDL_Window* window, SDL_GLContext& context);
    void close();
    void render();
    class Builder;

private:
    SDL_Window* window;
    SDL_GLContext context;
};

class Window::Builder {
public:
    Builder();
    Window build();
    Builder& setTitle(std::string title);
    Builder& setSize(int size);

private:
    std::string title;
    int size;
};

#endif