#pragma once
#include "ShaderProgram.h"
#include "IDrawable.h"


class Material : public IDrawable, public IGameObject
{
	ShaderProgram* shader;
public:
	Material(ShaderProgram& shader);
	Material(Material& other);
	void draw() override;
};

