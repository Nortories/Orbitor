/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testObject.h"
//#include "testAngle.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestObject().run();
}

void testObject()
{
   TestObject().run();
}
void testAngle()
{
   //TestAngle().run();
}
