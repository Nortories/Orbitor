#include "StarLink.h"
#include "object.h"
#include "StarLinkArray.h"
#include "StarLinkBody.h"

StarLink::StarLink() : Object()
{
	this->position.setMeters(STARLINK_POSITION_X, STARLINK_POSITION_Y);
	this->velocity.setDx(STARLINK_VECTOR_X);
	this->velocity.setDy(STARLINK_VECTOR_Y);
	radius = STARLINK_RADIUS;
}

void StarLink::draw(ogstream* gout)
{
	gout->drawStarlink(position, getDirection().getRadians());
}

list<Part*> StarLink::getPartPieces()
{
	list<Part*> pieces;

	StarLinkArray* array = new StarLinkArray(position, velocity, Angle(0));
	StarLinkBody* body = new StarLinkBody(position, velocity, Angle(0));

	pieces.push_back(array);
	pieces.push_back(body);

	return pieces;
}