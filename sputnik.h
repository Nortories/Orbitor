#include "object.h"
#include "fragment.h"

class Sputnik : public Object
{
public:
	Sputnik();
	void draw(ogstream* gout);
protected:
	list<Part*> getPartPieces();
};