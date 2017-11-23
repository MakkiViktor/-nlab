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
	static Mat4 S;
	static Mat4 R;
	static Mat4 T;
	Transform& trans;
	vector<IGameObject*> components;
public:
	Actor(Transform & trans);
	void addComponent(IGameObject& component);
	void addComponents(vector<IGameObject*>& components);
	Transform& transform();
	void onEndFrame() override;
};

