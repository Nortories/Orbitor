#pragma once
#include "object.h"
#include "projectile.h"
#include <vector>
#include <cassert>

class Game
{
public:
	Game() {};
	void start(){
		//setup
		_objects.push_back(Object("earth", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		/*objects.push_back(Object("moon", Position(0.0, 384400000), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("mars", Position(0.0, 227900000), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("venus", Position(0.0, 108200000), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("mercury", Position(0.0, 57910000), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("sun", Position(0.0, 0.0), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("jupiter", Position(0.0, 778500000), false, true, 1.0, 1.0, 100, 0.0, 0.0, 0.0, 0.0, 10000, 9999));
		objects.push_back(Object("saturn", Position(0.0, 1433000000), false, true, 1.0, 1.0, ));*/
		_objects.push_back(Object());
		_objects.push_back(Object());
		_objects.push_back(Object());
		_objects.push_back(Object());
		_objects.push_back(Object());

	}


private:
	vector<Object> _objects;
	vector<Projectile> _projectiles;
};