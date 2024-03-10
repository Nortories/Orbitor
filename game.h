#pragma once
#include "object.h"
#include "projectile.h"
#include <vector>
#include <cassert>
#include "config.h"
#include "stars.h"
#include "uiDraw.h"

class Game
{
public:
	Game() :
		star(ptUpperRight),
		_gout(this->pt)
	{
		// It sets the init GPS position
		ptGPS.setPixelsX(0.0);
		ptGPS.setPixelsY(GEOSTATIONARY_ORBIT);

		// It sets the init Hubble position
		ptHubble.setPixelsX(0.0);
		ptHubble.setPixelsY(GEOSTATIONARY_ORBIT);

		// It sets the init Star position
		ptStar.setPixelsX(0.0);
		ptStar.setPixelsY(GEOSTATIONARY_ORBIT);

		ptUpperRight = Position(0, 0);
	}

	Game(Position pUpperRight) :
		star(pUpperRight),
		_gout(this->pt)

	{
		// It sets the init GPS position
		ptGPS.setPixelsX(0.0);
		ptGPS.setPixelsY(GEOSTATIONARY_ORBIT);

		// It sets the init Hubble position
		ptHubble.setPixelsX(0.0);
		ptHubble.setPixelsY(GEOSTATIONARY_ORBIT);

		// It sets the init Star position
		ptStar.setPixelsX(0.0);
		ptStar.setPixelsY(GEOSTATIONARY_ORBIT);

		ptUpperRight = pUpperRight;

	}

	void update(){}
	void draw(ogstream* gout){

	star.draw(&_gout);
	//ogstream gout.drawEarth(this->pt, EARTH_FULL_ROTATION);
	cout << "draw" << endl;
	
	}

	bool isRunning() { return gameRunning; }




private:
	vector<Object> _objects;
	vector<Projectile> _projectiles;
	Position ptHubble;
	Position ptGPS;
	Position ptStar;
	Position ptUpperRight;
	//   Position ptSputnik;
	//   Position ptStarlink;
	//   Position ptCrewDragon;
	//   Position ptShip;

	Position pt;
	ogstream _gout;
	Star star;

	bool gameRunning = true;
};