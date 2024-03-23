#pragma once
#include "object.h"
#include "fragment.h"


class Hubble : public Object
{
public:
	Hubble();
	void draw(ogstream* gout);
protected:
	list<Part*> getPartPieces();
};