#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <cmath>

class Camera {
public:
    Camera();
    glm::mat4 getMVP();
    void update(double interval);
    void move(glm::vec3 delta);
    void rotate(double delta);
    void instaHorizRotate(double delta);
    void instaVertiRotate(double delta);

private:
    glm::vec3 position;
    glm::vec3 positionDelta;
    glm::vec3 front;
    double frontDelta;
    glm::vec3 up;
};
