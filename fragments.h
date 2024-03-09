#pragma once

#include "position.h"

class Fragment {
public:
	Fragment() : dx(0.0), dy(0.0), pos(Position(0,0))
		{}

private:
	float dx;
	float dy;
	Position pos;
};