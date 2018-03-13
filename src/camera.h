#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
    Camera();
    glm::mat4 getMVP();
    void update(double interval);
    void move(glm::vec3 delta);

private:
    glm::vec3 position;
    glm::vec3 positionDelta;
    glm::vec3 eyesOn;
    glm::vec3 eyesOnDelta;
};
