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
#include "testPhysics.h"
#include "testObject.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void Test::testRunner()
{
   TestPosition().run();
   cout << "Test Position pass" << endl;
   TestPhysics().run();
   cout << "Test Physics pass" << endl;
   TestObject().run();
   cout << "Test Object pass" << endl;
}
