#pragma once
#include <vector>
#include <functional>

using namespace std;

class GameBehaviour
{
public:
	GameBehaviour();
	void add(GameBehaviour* gob);
	void callInit();
	void callOnStartFrame();
	void callOnEndFrame();
	virtual void init() {}
	virtual void onStartFrame() {}
	virtual void onEndFrame() {}
};

