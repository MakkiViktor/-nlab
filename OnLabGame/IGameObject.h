#pragma once
#include <vector>
#include "GameBehaviour.h"
#include <typeinfo.h>


using namespace std;

class IGameObject : public GameBehaviour{
protected:
	vector<IGameObject*> components;
	IGameObject* parent = nullptr;
public:	
	static string TAG;
	string tag = IGameObject::TAG;
	void addComponent(IGameObject* component);
	vector<IGameObject*>& getComponents();
	IGameObject* getRoot();
	IGameObject* getParent();
	
	template<class T> 
	T* getComponent() {
		return findComponentIn<T>(getRoot());
	}

	template<class T>
	static T* findComponentIn(IGameObject* gob) {
		cout << T::TAG;
		if (strcmp(gob->tag.c_str(), T::TAG.c_str()) == 0)
			return static_cast<T*>(gob);
		for each (auto g in gob->getComponents())
		{
			return findComponentIn<T>(g);
		}
		return nullptr;
	}
};
