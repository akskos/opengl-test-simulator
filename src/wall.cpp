#include "wall.h"

Wall::Wall(glm::vec3 position, glm::vec3 wallVector, float thickness) {
    glm::vec3 thicknessVector = glm::normalize(glm::cross(wallVector, glm::vec3(0, 1, 0))) * thickness;
    Rect* r0 = new Rect(
	glm::vec3(position.x, position.y, position.z + wallVector.z),
	glm::vec3(position.x + wallVector.x, position.y, position.z),
	glm::vec3(position.x + wallVector.x, position.y + 8, position.z),
	glm::vec3(position.x, position.y + 8, position.z + wallVector.z)
    );
    rects.push_back(r0);
    Rect* r1 = new Rect(
	glm::vec3(position.x + thicknessVector.x, position.y, position.z + wallVector.z - thicknessVector.z),
	glm::vec3(position.x + wallVector.x + thicknessVector.x, position.y, position.z - thicknessVector.z),
	glm::vec3(position.x + wallVector.x + thicknessVector.x, position.y + 8, position.z - thicknessVector.z),
	glm::vec3(position.x + thicknessVector.x, position.y + 8, position.z + wallVector.z - thicknessVector.z)
    );
    rects.push_back(r1);
    Rect* r2 = new Rect(
	glm::vec3(position.x, position.y, position.z + wallVector.z),
	glm::vec3(position.x + thicknessVector.x, position.y, position.z + wallVector.z - thicknessVector.z),
	glm::vec3(position.x + thicknessVector.x, position.y + 8, position.z + wallVector.z - thicknessVector.z),
	glm::vec3(position.x, position.y + 8, position.z + wallVector.z)
    );
    rects.push_back(r2);
    Rect* r3 = new Rect(
	glm::vec3(position.x + wallVector.x, position.y, position.z),
	glm::vec3(position.x + wallVector.x, position.y + 8, position.z),
	glm::vec3(position.x + wallVector.x + thicknessVector.x, position.y + 8, position.z - thicknessVector.z),
	glm::vec3(position.x + wallVector.x + thicknessVector.x, position.y, position.z - thicknessVector.z)
    );
    rects.push_back(r3);
}

void Wall::setColor(glm::vec3 color) {
    for (int i = 0; i < rects.size(); i++) {
	rects[i]->setColor(color);
    }
}

void Wall::render() {
    for (int i = 0; i < rects.size(); i++) {
	rects[i]->render();
    }
}
