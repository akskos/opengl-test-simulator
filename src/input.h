#include <GLFW/glfw3.h>
#include <stdlib.h>

namespace input {
    void keyboardCallback(
	    GLFWwindow *window, 
	    int key, 
	    int scancode, 
	    int action, 
	    int mods) {

	if (key == GLFW_KEY_ESCAPE) {
	    glfwTerminate();
	    exit(0); 
	}
    }
};
