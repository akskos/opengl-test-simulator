#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
    Camera();
    glm::mat4 getMVP();
    void move(glm::vec3 delta);

private:
    glm::vec3 position;
    glm::vec3 eyesOn;
};
