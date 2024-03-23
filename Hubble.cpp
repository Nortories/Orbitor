#include "Hubble.h"
#include "object.h"
#include "HubbleComputer.h"
#include "HubbleRight.h"
#include "HubbleLeft.h"
#include "HubbleTelescope.h"

Hubble::Hubble() : Object()
{
	this->position.setMeters(HUBBLE_POSITION_X, HUBBLE_POSITION_Y);
	this->velocity.setDx(HUBBLE_VECTOR_X);
	this->velocity.setDy(HUBBLE_VECTOR_Y);
	radius = HUBBLE_RADIUS;
}

void Hubble::draw(ogstream* gout)
{
	gout->drawHubble(position, getDirection().getRadians());
}

list<Part*> Hubble::getPartPieces()
{
	list<Part*> pieces;

	HubbleComputer* computer = new HubbleComputer(position, velocity, Angle(0));
	HubbleRight* right = new HubbleRight(position, velocity, Angle(0));
	HubbleLeft* left = new HubbleLeft(position, velocity, Angle(0));
	HubbleTelescope* telescope = new HubbleTelescope(position, velocity, Angle(0));

	pieces.push_back(computer);
	pieces.push_back(right);
	pieces.push_back(left);
	pieces.push_back(telescope);

	return pieces;
}