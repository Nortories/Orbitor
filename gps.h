#include "object.h"
#include "fragment.h"


class GPS : public Object
{
public:
	GPS(float posX, float posY, float velX, float velY);
	void draw(ogstream* gout);
protected:
	list<Part*> getPartPieces();
};