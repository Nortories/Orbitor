#pragma once
#include "object.h"
#include "fragment.h"

class Dragon : public Object
{
public:
	Dragon();
	void draw(ogstream* gout);
protected:
	list<Part*> getPartPieces();
};