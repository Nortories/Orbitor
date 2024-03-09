#pragma once
#include "position.h"
#include "config.h"

class Projectile
{
public:
	Projectile() {
		pos = Position(0, 0);
		angle = 0;
		gravity = 0;
		radius = 0;
		mass = 0;
		isEnemy = false;
	};

	Projectile(Position pos, double angle, double speed, double gravity, double radius, double mass, double damage, bool isEnemy)
		: pos(pos), angle(angle), speed(speed), gravity(gravity), radius(radius), mass(mass), damage(damage), isEnemy(isEnemy) 
	{};

	Position getPosition() const { return pos; }
	double getAngle() const { return angle; }
	double getSpeed() const { return speed; }
	double getGravity() const { return gravity; }
	double getRadius() const { return radius; }
	double getMass() const { return mass; }
	double getDamage() const { return damage; }
	bool getIsEnemy() const { return isEnemy; }
	void setPosition(Position pos) { this->pos = pos; }
	void setAngle(double angle) { this->angle = angle; }
	void setSpeed(double speed) { this->speed = speed; }
	void setGravity(double gravity) { this->gravity = gravity; }
	void setRadius(double radius) { this->radius = radius; }
	void setMass(double mass) { this->mass = mass; }
	void setDamage(double damage) { this->damage = damage; }
	void setIsEnemy(bool isEnemy) { this->isEnemy = isEnemy; }

	private:
		Config config;

		Position pos;
		double angle;
		double speed = config.getProjectileSpeed();
		double gravity;
		double radius;
		double mass;
		double damage = 1;
		bool isEnemy;
};