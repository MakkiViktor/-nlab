#include "Timer.h"

void Timer::start()
{
	glfwSetTime(glfwGetTime());
}

double Timer::timeEllapsed()
{
	return glfwGetTime();
}
