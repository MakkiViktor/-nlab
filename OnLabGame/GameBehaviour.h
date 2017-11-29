#pragma once
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class GameBehaviour
{
public:
	GameBehaviour();
	static void add(GameBehaviour* gob);	
	static void remove(GameBehaviour* gob);
	static void callInit();
	static void callOnStartFrame();	
	static void callOnDrawFrame();
	static void callOnDrawUpdateFrame();
	static void callOnEndFrame();
	static void callDestroy();	

	virtual void init() {}
	virtual void onStartFrame() {}
	virtual void onDrawUpdateFrame() {}
	virtual void onDrawFrame() {}
	virtual void onEndFrame() {}
	virtual void destroy() {}

};

