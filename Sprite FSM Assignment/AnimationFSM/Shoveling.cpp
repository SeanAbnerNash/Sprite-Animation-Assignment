#include "Shoveling.h"
#include <Jumping.h>
#include <Walking.h>
#include <Climbing.h>
#include <Idle.h>

#include <string>

void Shoveling::idle(Animation* a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Shoveling::jumping(Animation* a)
{
	std::cout << "Shoveling -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}


void Shoveling::walking(Animation * a)
{
	std::cout << "Shoveling -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Shoveling::climbing(Animation * a)
{
	std::cout << "Shoveling -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}
