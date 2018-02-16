#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
    Camera();
    glm::mat4 getMVP();

private:
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
};
