#pragma once
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class GameBehaviour
{
public:
	GameBehaviour();
	virtual void add(GameBehaviour* gob);
	void callInit();
	void callOnStartFrame();
	void callOnEndFrame();
	virtual void init() {}
	virtual void onStartFrame() {}
	virtual void onEndFrame() {}
	virtual void remove(GameBehaviour* gob);
};

