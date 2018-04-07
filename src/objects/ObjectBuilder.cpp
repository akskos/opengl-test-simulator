#include "ObjectBuilder.h"

namespace object_builder {
  using namespace std;

  Renderable* buildWorld() {
    World* world = new World();
    vector<Rect*> tunnel_rects = buildTunnel();
    vector<Renderable*> renderables(tunnel_rects.size());
    copy(tunnel_rects.begin(), tunnel_rects.end(), renderables.begin());
    world->addObjects(renderables);
    return world;
  }
  
  vector<Rect*> buildTunnel() {
    vector<Rect*> rects;
    rects.push_back(new Rect(
      glm::vec3(9, -2, 18),
      glm::vec3(18, -2, 18),
      glm::vec3(18, -2, 30),
      glm::vec3(9, -2, 30),
      glm::vec3(1.0, 0.4, 0.7)
    ));
    rects.push_back(new Rect(
      glm::vec3(9, -2, 18),
      glm::vec3(9, 5, 18),
      glm::vec3(9, 5, 30),
      glm::vec3(9, -2, 30),
      glm::vec3(0.4f, 1.0f, 0.7f)
    ));
    rects.push_back(new Rect(
      glm::vec3(18, -2, 18),
      glm::vec3(18, 5, 18),
      glm::vec3(18, 5, 30),
      glm::vec3(18, -2, 30),
      glm::vec3(0.7f, 0.3f, 1.0f)
    ));
    rects.push_back(new Rect(
      glm::vec3(9, 5, 18),
      glm::vec3(18, 5, 18),
      glm::vec3(18, 5, 30),
      glm::vec3(9, 5, 30),
      glm::vec3(0.2f, 0.4f, 0.7f)
    ));

    return rects;
  }
}
