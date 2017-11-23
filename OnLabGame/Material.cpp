#include "Material.h"

Material::Material(ShaderProgram& shader): shader(&shader) {
	IGameObject::addComponent(&shader);
}

Material::Material(Material & other):Material(*other.shader){
}

void Material::draw() {
	shader->use();
}


