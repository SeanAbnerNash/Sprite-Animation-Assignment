#include "Walking.h"

#include <Jumping.h>
#include <Idle.h>
#include <Shoveling.h>

#include <string>

void Walking::idle(Animation* a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Walking::jumping(Animation* a)
{
	std::cout << "Walking -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Walking::shoveling(Animation * a)
{
	std::cout << "Walking -> Shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}
