#include "Mesh.h"



Mesh::Mesh(Material & material, Geometry & geometry) : material(&material), geometry(&geometry){
	IGameObject::addComponent(&material);
	IGameObject::addComponent(&geometry);
}


void Mesh::onEndFrame() {
	Actor::onEndFrame();
	draw();
}

void Mesh::addSubMesh(Mesh & subMesh) {
	subMeshes.push_back(&subMesh);
	IGameObject::addComponent(&subMesh);
}

// hozzáfúz a vectorhoz
void Mesh::addSubMeshes(vector<Mesh*>& subMeshes) {
	this->subMeshes.insert(std::end(this->subMeshes), std::begin(subMeshes), std::end(subMeshes));
	for each (auto a in subMeshes)
	{
		IGameObject::addComponent(a);
	}
}

void Mesh::draw()
{
	for each (auto var in subMeshes) {
		var->draw();
	}
	material->draw();
	geometry->draw();
}
