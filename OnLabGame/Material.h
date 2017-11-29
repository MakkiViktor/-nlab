#pragma once
#include "ShaderProgram.h"
#include "IDrawable.h"


class Material : public IDrawable, public IGameObject
{
	ShaderProgram* shader;
	Vec3 color;
public:
	static string TAG;
	string tag = Material::TAG;
	Material(ShaderProgram& shader, Vec3& color);
	Material(ShaderProgram& shader);
	Material(Material& other);
	void draw() override;
	void init() override;
};

