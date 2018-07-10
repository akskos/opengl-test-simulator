#include "input.h"

using namespace std;
typedef Util::Direction Direction;

InputController::InputController() {
    w = new MoveCommand(Direction::FORWARD);
    a = new MoveCommand(Direction::LEFT);
    s = new MoveCommand(Direction::BACK);
    d = new MoveCommand(Direction::RIGHT);
    mouseMove = new RotateCommand();
    leftMouseClick = nullptr;
}

vector<Command*> InputController::pollCommands() {
    vector<Command*> commands;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
            case SDLK_a:
                a->setDown(true);
                commands.push_back(a);
                break;
            case SDLK_d:
                d->setDown(true);
                commands.push_back(d);
                break;
            case SDLK_w:
                w->setDown(true);
                commands.push_back(w);
                break;
            case SDLK_s:
                s->setDown(true);
                commands.push_back(s);
                break;
            default:
                break;
            }
        } else if (event.type == SDL_KEYUP) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
            case SDLK_a:
                a->setDown(false);
                commands.push_back(a);
                break;
            case SDLK_d:
                d->setDown(false);
                commands.push_back(d);
                break;
            case SDLK_w:
                w->setDown(false);
                commands.push_back(w);
                break;
            case SDLK_s:
                s->setDown(false);
                commands.push_back(s);
                break;
            default:
                break;
            }
        } else if (event.type == SDL_MOUSEMOTION) {
            mouseMove->setCoordinates(
                event.motion.xrel,
                event.motion.yrel
            );
            commands.push_back(mouseMove); 
        } else if (event.type == SDL_QUIT) {
            // Quit
        }
    }

    return commands;
}