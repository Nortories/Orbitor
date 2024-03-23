#pragma once
#include "object.h"
#include "fragment.h"

class StarLink : public Object
{
public:
	StarLink();
	void draw(ogstream* gout);
protected:
	list<Part*> getPartPieces();
};