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
	Object() : angle(0), radius(0), angularVelocity(0), hitPoints(1), mass(0) {
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
		this->hitPoints = 1;
		this->mass = 0;
	}

	//getters
	string getType() const { return type; }
	Velocity getVelocity() const { return velocity; }
	Position getPosition() const { return position; }
	Angle getAngle() const { return angle; }
	float getRadius() const { return radius; }
	float getAngularVelocity() const { return angularVelocity; }
	int getHitPoints() const { return hitPoints; }
	float getMass() const { return mass; }
	bool isDead() const { return selfDestruct; }


	//setters
	void setType(string type) { this->type = type; }
	void setVelocity(Velocity velocity) { this->velocity = velocity; }
	void setPosition(Position position) { this->position = position; }
	void setAngle(Angle angle) { this->angle = angle; }
	void setRadius(float radius) { this->radius = radius; }
	void setAngularVelocity(float angularVelocity) { this->angularVelocity = angularVelocity; }
	void setIsddead(bool destroyed) { this->selfDestruct = destroyed; }
	void setHitPoints(int hitPoints) { this->hitPoints = hitPoints; }
	void setMass(float mass) { this->mass = mass; }

	//member functions
	virtual void draw(ogstream* gout) {/*override and draw self*/
		gout->drawCrewDragon(position, 0);
	}

	void triggerDestruction() 
	{
		selfDestruct = true; }

	virtual void explode(list<Object*>* objList);

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

	void updatePosition()
	{
		float newGravity = getGravity(position);
		update(FPS, newGravity);
		angle.rotate(this->angularVelocity);
	}

	bool isHit(Object* obj)
	{
		float distance = sqrt((position.getMetersX() - obj->position.getMetersX()) * (position.getMetersX() - obj->position.getMetersX()) +
			(position.getMetersY() - obj->position.getMetersY()) * (position.getMetersY() - obj->position.getMetersY()));
		float hitBox = (radius + obj->radius) * 128000;
		if (distance <= hitBox)
		{
			this->hitPoints--;
			if (this->hitPoints <= 0)
			{
				this->selfDestruct = true;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool crashedOnEarth()
	{
		float distance = sqrt(position.getMetersX() * position.getMetersX() + position.getMetersY() * position.getMetersY());
		float radii = (radius + ZOOM) + RADIUS_OF_EARTH;
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
	// Use this function to set each child class's parts 
	virtual list<Part*> getPartPieces();
	
	float getGravity(const Position& pos)
	{
		// First get the height from earth.
		float height = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - RADIUS_OF_EARTH;
		// Then calculate the gravity at that height.
		float newGravity = GRAVITY * ((RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)) * (RADIUS_OF_EARTH / (RADIUS_OF_EARTH + height)));
		return newGravity;
	};

	Angle getDirection() const
	{
		return Angle(atan2(velocity.getDx(), velocity.getDy()));
	};

	Angle getDirectionGravity() const
	{
		return Angle(atan2(position.getMetersX(), position.getMetersY()));
	};


	//member variables
	string type = "none";
	Velocity velocity;
	Position position;
	Angle angle;
	float radius;
	float angularVelocity;
	int hitPoints = 1;
	float mass;
	bool selfDestruct = false;

};