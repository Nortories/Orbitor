#pragma once
#include "bullet.h"
#include "object.h"

class StarShipEnterprise : public Object
{
public:
	StarShipEnterprise()
	{
		this->velocity = Velocity();
		this->position = Position(21082000, 36515095.125);
		this->angle = Angle();
		this->angularVelocity = 0.00;
		this->dead = false;
		this->radius = 5.00;
		this->thrust = false;
	};
	StarShipEnterprise(const Velocity& vel, const Position& pos, const Angle& ang, float angular);
	void draw(ogstream* gout)
	{
		gout->drawShip(position, angle.getRadians(), thrust);
	}
	void flyShip();

	void rotateLeft() { angle.setRadians(angle.getRadians() - 0.1); };
	void rotateRight() { angle.setRadians(angle.getRadians() + 0.1); };
	void setThrust(bool thrust) { this->thrust = thrust; };
	Bullet* fire();

private:
	bool thrust;
	list<Part*> getDebris();
};

