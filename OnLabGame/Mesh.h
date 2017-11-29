#pragma once
#include <vector>
#include "IDrawable.h"
#include "Material.h"
#include "Geometry.h"
#include "Actor.h"
#include "Transform.h"

using namespace std;

class Mesh : public Actor, public IDrawable
{
	Material material;
	Geometry geometry;
	vector<Mesh*> subMeshes;

public:
	Mesh(Material& material, Geometry& geometry);
	Mesh(Mesh& other);
	void onDrawFrame() override;
	void draw() override;
	void addSubMesh(Mesh& subMesh);
	void addSubMeshes(vector<Mesh*>& subMeshes);
};

