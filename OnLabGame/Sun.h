#pragma once
#include "Actor.h"
class Sun : public Actor
{
public:
	static string TAG;
	Sun();
	Sun(Vec3 position);
	~Sun();
	void init() override;
	void onDrawUpdateFrame() override;
};

