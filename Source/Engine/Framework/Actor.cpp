#include "../Framework/Actor.h"
#include "../Renderer/Model.h"
void bonzai::Actor::update(float deltaTime) {
	transform.position += velocity * deltaTime;
	velocity *= (1.0f / (1.0f + damping)); // Dampen the velocity to simulate friction
}

void bonzai::Actor::draw(Renderer& renderer) {
	model->draw(renderer, transform);
}
