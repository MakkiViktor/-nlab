#include "Mesh.h"



Mesh::Mesh(Material & material, Geometry & geometry) : material(material), geometry(geometry){
	IGameObject::addComponent(&material);
	IGameObject::addComponent(&geometry);
}

Mesh::Mesh(Mesh & const other):Mesh(other.material, other.geometry){}

void Mesh::onEndFrame() {
	draw();
}

void Mesh::addSubMesh(Mesh & subMesh) {
	subMeshes.push_back(&subMesh);
	IGameObject::addComponent(&subMesh);
}

// hozzáfúz a vectorhoz
void Mesh::addSubMeshes(vector<Mesh*>& subMeshes) {
	for each (auto a in subMeshes)
	{
		this->subMeshes.push_back(a);
		IGameObject::addComponent(a);
	}
}

void Mesh::draw()
{
	for each (auto var in subMeshes) {
		var->draw();
	}
	material.draw();
	geometry.draw();
}
