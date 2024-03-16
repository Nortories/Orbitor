#pragma once

#include <iostream>
#include <string>
#include "uiDraw.h"
#include "position.h"
#include "velocity.h"
#include "angle.h"
#include <list>
#include "config.h"

using namespace std;
class Part;

class Object
{
public:
	//default constructor
	Object() : angle(0), radius(0), angularVelocity(0), destroyed(false), hitPoints(1), mass(0) {
		this->velocity = Velocity(0, 0);
		this->position = Position(0, 0);
	}

	//min constructor
	Object(Velocity velocity, Position position, Angle angle) {
		this->type = type;
		this->velocity = velocity;
		this->position = position;
		this->angle = angle;
		this->radius = 0;
		this->angularVelocity = 0;
		this->destroyed = false;
		this->hitPoints = 1;
		this->mass = 0;
	}

	//everything constructor
	Object(string type, Velocity velocity, Position position, Angle angle, float radius, float angularVelocity, bool destroyed, int hitPoints, float mass) {
		this->type = type;
		this->velocity = velocity;
		this->position = position;
		this->angle = angle;
		this->radius = radius;
		this->angularVelocity = angularVelocity;
		this->destroyed = destroyed;
		this->hitPoints = hitPoints;
		this->mass = mass;
	}


	//getters
	string getType() const { return type; }
	Velocity getVelocity() const { return velocity; }
	Position getPosition() const { return position; }
	Angle getAngle() const { return angle; }
	float getRadius() const { return radius; }
	float getAngularVelocity() const { return angularVelocity; }
	bool getIsDestroyed() const { return destroyed; }
	int getHitPoints() const { return hitPoints; }
	float getMass() const { return mass; }


	//setters
	void setType(string type) { this->type = type; }
	void setVelocity(Velocity velocity) { this->velocity = velocity; }
	void setPosition(Position position) { this->position = position; }
	void setAngle(Angle angle) { this->angle = angle; }
	void setRadius(float radius) { this->radius = radius; }
	void setAngularVelocity(float angularVelocity) { this->angularVelocity = angularVelocity; }
	void setIsDestroyed(bool destroyed) { this->destroyed = destroyed; }
	void setHitPoints(int hitPoints) { this->hitPoints = hitPoints; }
	void setMass(float mass) { this->mass = mass; }

	//member functions
	virtual void draw(ogstream* gout) {/*override and draw self*/
		gout->drawCrewDragon(position, 0);
	}

	void triggerDestruction() 
	{ destroyed = true; }

	virtual void destroy(list<Object*>* objList);

	void update(float time, float gravity) {
		// update the velocity of the object
		float gravityDirection = atan2(position.getMetersX(), position.getMetersY());

		float ddx = gravity * sin(gravityDirection);
		float ddy = gravity * cos(gravityDirection);

		float newDx = velocity.getDx() + (ddx * time);
		float newDy = velocity.getDy() + (ddy * time);

		velocity.setDx(newDx);
		velocity.setDy(newDy);
		
		// update new position of the object
		float newX = position.getMetersX() + (velocity.getDx() * time);
		float newY = position.getMetersY() + (velocity.getDy() * time);
		position.setMetersX(newX);
		position.setMetersY(newY);
	}

	void move()
	{
		float aGravity = getGravity(position);
		update(aGravity, FPS);
		angle.rotate(this->angularVelocity);
	}
	bool hit(Object* obj)
	{
		float distance = sqrt((position.getMetersX() - obj->position.getMetersX()) * (position.getMetersX() - obj->position.getMetersX()) +
			(position.getMetersY() - obj->position.getMetersY()) * (position.getMetersY() - obj->position.getMetersY()));
		float hitBox = (radius + obj->radius) * 128000;
		if (distance <= hitBox)
		{
			this->hitPoints--;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool earthCrash()
	{
		float distance = sqrt((position.getMetersX() - 0) * (position.getMetersX() - 0) +
			(position.getMetersY() - 0) * (position.getMetersY() - 0));
		float radii = (radius + 128000) + RADIUS_OF_EARTH;
		if (distance < radii)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


protected:
	//member functions
	float getGravity(const Position& pos)
	{
		// First get the height from earth.
		float height = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - RADIUS_OF_EARTH;
		// Then calculate the gravity at that height.
		float gravity = GRAVITY * ((RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)) * (RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)));
		return gravity;
	};

	Angle getDirection() const
	{
		return Angle(atan2(velocity.getDx(), velocity.getDy()));
	};

	Angle getDirectionGravity() const
	{
		return Angle(atan2(position.getMetersX(), position.getMetersY()));
	};

	virtual list<Part*> getParts();



	//member variables
	string type = "none";
	Velocity velocity;
	Position position;
	Angle angle;
	float radius;
	float angularVelocity;
	bool destroyed;
	int hitPoints = 1;
	float mass;

};