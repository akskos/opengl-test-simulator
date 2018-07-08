#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <cmath>
#include <iostream>

#include "config.h"
#include "actors/Actor.h"
#include "Graphics.h"
#include "events/Event.h"

class Camera: public Actor {
public:
    Camera();
    glm::mat4 getMVP();
    void setXMoveVector(glm::vec3 vec);
    void setZMoveVector(glm::vec3 vec);
    void rotate(double delta);
    void vrotate(double delta);
    void instaHorizRotate(double delta);
    void instaVertiRotate(double delta);

    void update(double interval);
    void render(Graphics graphics);
    void handleEvent(Event event);

private:
    glm::vec3 xMoveVector;
    glm::vec3 zMoveVector;
    glm::vec3 position;
    glm::vec3 positionDelta;
    glm::vec3 front;
    double frontDelta;
    double vrotateDelta;
    glm::vec3 up;
    const float near_clip = 0.1;
    const float far_clip = 50.0;
    const float aspect_ratio = 1.0;

    void move(glm::vec3 vec, double interval);
};
