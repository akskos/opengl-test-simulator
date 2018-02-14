#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <functional>
#include <map>

class InputController {
public:
    void keyboardCallback(
	    GLFWwindow *window,
	    int key, 
	    int scancode, 
	    int action,
	    int mods);
    void addBinding(int key, int action, std::function<void()> callback);

private:
    std::map<int, std::map<int, std::function<void()>>> callbacks;
};
