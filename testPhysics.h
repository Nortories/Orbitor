/***********************************************************************
 * Heaader File:
 *    Test : TestObjects
 * Author:
 *    Joshua & Kai
 * Summary:
 *    This is the test driver for the physics class. It is responsible
 *    for testing the Physics class. 
 ************************************************************************/
#pragma once

#include "physics.h"
#include "object.h"
#include "position.h"
#include <cassert>

class TestPhysics
{
public:
	void run() {

		// positional calculations
//		testCalculateNewPosBase();
//		testCalculateNewPosConstantAcceleration();
		// acceleration calculations
		testCalculateDDX();
		testCalculateDDY();
		// velocity calculations
		testCalculateDX();
		testCalculateDY();
	}
   
   /******************************************
      CLOSE ENOUGH
      The function helps solve decimal issues.
   *******************************************/
   bool closeEnough(double lhs, double rhs, double presicion)
   {
      return (lhs-presicion) < (rhs+presicion) && (lhs+presicion) > (rhs-presicion);
   }

	/***************************************************
	*	Test Physics calculateddx()
	***************************************************/
	void testCalculateDDX() {
		//setup

		//execute

		//verify
		assert(closeEnough(5, calculateDDX(10, 30), 0.1));
	}

	/***************************************************
	*	Test Physics calculateDDY()
	***************************************************/
	void testCalculateDDY() {
		//setup

		//execute

		//verify
      assert(closeEnough(8.66, calculateDDY(10, 30), 0.1));
	}

	/***************************************************
	* Test Physics calculateDX()
	* ***************************************************/
	void testCalculateDX() {
		//setup

		//execute

		//verify
		assert(2 == calculateDX(1, 1, 1));
      assert(4 == calculateDX(0, 2, 2));
	}

	/***************************************************
	* Test Physics calculateDY()
	***************************************************/
	void testCalculateDY() {
		//setup

		//execute

		//verify
      assert(2 == calculateDY(1, 1, 1));
      assert(4 == calculateDY(0, 2, 2));
	}

   /***************************************************
   * Test calculate distance()
   ***************************************************/
   void testCalculateDistance()
   {
      //setup

      //execute

      //verify
      assert(closeEnough(2.236, calculateDistance(1, 2), 0.1));
   }
   
   /***************************************************
   * Test calculate angle()
   ***************************************************/
   void testCalculateAngle()
   {
      //setup

      //execute

      //verify
      assert(closeEnough(1.107, calculateAngle(1, 2), 0.1));
   }
};
