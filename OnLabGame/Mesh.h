#pragma once
#include <vector>
#include "IDrawable.h"
#include "Material.h"
#include "Geometry.h"
#include "IGameObject.h"
#include "Transform.h"

using namespace std;

class Mesh : public IGameObject, public IDrawable
{
	Material material;
	Geometry geometry;
	vector<Mesh*> subMeshes;

public:
	Mesh(Material& material, Geometry& geometry);
	Mesh(Mesh& other);
	void onEndFrame() override;
	void draw() override;
	void addSubMesh(Mesh& subMesh);
	void addSubMeshes(vector<Mesh*>& subMeshes);
};

