#include "Material.h"

Material::Material(ShaderProgram& shader): shader(&shader) {
	IGameObject::addComponent(&shader);
}

void Material::draw() {
	shader->use();
}


