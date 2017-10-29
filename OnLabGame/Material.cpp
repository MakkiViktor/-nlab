#include "Material.h"

Material::Material(ShaderProgram& shader): shader(&shader) {}

void Material::draw() {
	shader->use();
}


