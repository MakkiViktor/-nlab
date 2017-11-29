#include "Material.h"

string Material::TAG("Material");

Material::Material(ShaderProgram & shader, Vec3& color):shader(&shader), color(color){	
	IGameObject::addComponent(&shader);
}

Material::Material(ShaderProgram& shader): Material(shader, Vec3(1,1,1)) {
}

Material::Material(Material & other):Material(*other.shader, other.color){
}

void Material::draw() {
	ShaderProgram::setSharedUniform("color", color);
	shader->use();
}

void Material::init()
{
	ShaderProgram::addSharedUniform(sharedUniform(color, VEC3, "color"));
}


