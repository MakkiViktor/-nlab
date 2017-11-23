#pragma once
#include <vector>
#include "Material.h"
#include "Geometry.h"
#include "IGameObject.h"
#include "Transform.h"
#include "ShaderProgram.h"
#include <memory>

using namespace std;

class Actor : public IGameObject
{
	static Mat4 M;
	Transform& trans;
public:
	Actor(Transform & trans);
	Transform& transform();
	void onEndFrame() override;
};

