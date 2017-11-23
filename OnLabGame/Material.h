#pragma once
#include "ShaderProgram.h"
#include "IDrawable.h"


class Material : public IDrawable, public IGameObject
{
	ShaderProgram* shader;
public:
	Material(ShaderProgram& shader);
	void draw() override;
};

