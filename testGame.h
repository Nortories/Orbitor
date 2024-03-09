/***********************************************************************
 * Heaader File:
 *    Test : TestObjects
 * Author:
 *    Joshua & Kai
 * Summary:
 *    This is the unit test for the game class. It is responsible
 * for testing the game class functions.
 ************************************************************************/

#pragma once

#include "game.h"
#include "object.h"
#include <vector>
#include <cassert>



using namespace std;

class TestGame
{
private:

	/***************************************************
	 *	Test Object default constructor
	 ***************************************************/
	void testGameDefaultConstructor() const {
		//setup
		Game game;
		game.start();
		//verify setup
		assert(game.getObjects().size() == 0);

	}

	vector<Object> objects;

};