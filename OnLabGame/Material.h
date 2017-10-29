#pragma once
#include "ShaderProgram.h"
#include "IDrawable.h"


class Material : public IDrawable
{
	ShaderProgram* shader;
public:
	Material(ShaderProgram& shader);
	void draw() override;
};

