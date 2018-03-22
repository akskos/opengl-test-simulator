#include <SDL2/SDL.h>
#include <stdlib.h>
#include <functional>
#include <map>

class InputController {
public:
    void keyboardCallback(SDL_Event event);
    void addBinding(SDL_Keycode, unsigned int action, std::function<void()> callback);

private:
    std::map<SDL_Keycode, std::map<int, std::function<void()>>> callbacks;
};
