#ifndef SHOVELING_H
#define SHOVELING_H

#include <State.h>

class Shoveling : public State
{
public:
	Shoveling() {};
	~Shoveling() {};
	void idle(Animation* a);
	void jumping(Animation* a);
	void walking(Animation* a);
	void climbing(Animation* a);
};
#endif // !SHOVELING_H