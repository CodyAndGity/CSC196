#include "../Framework/Actor.h"
#include "../Renderer/Model.h"
void bonzai::Actor::update(float deltaTime) {
	transform.position += velocity * deltaTime;
}

void bonzai::Actor::draw(Renderer& renderer) {
	model->draw(renderer, transform);
}
