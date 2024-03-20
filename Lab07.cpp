/*************************************************************
 * 1. Name:
 *      Josh and Kai
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      The math
 * 5. How long did it take for you to complete the assignment?
 *      5 hours
 *****************************************************************/

#define _USE_MATH_DEFINES // for cmath's M_PI
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <cmath>       // for MATH
#include <iomanip>
#include "physics.h"
#include "config.h"
#include "test.h"

#include "game.h"

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
      
      // It sets the init GPS position
      ptGPS.setPixelsX(0.0);
      ptGPS.setPixelsY(42164000);

//
      for (int i = 0; i < 50; i++)
      {
      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      stars[i] = ptStar;
      }
      

      

//      angleShip = 0.0;
      angleEarth = 0.0;
//      phaseStar = 0;
      
      // MATH
      angleRadians = 0.0;
//      angleRadians = angleDegrees * M_PI / 180.0;
      gpsX = 0;
      gpsY = geoDistance;
      dx = -geoSpeed;
      dy = 0;

      
   }

   Position ptHubble;
//   Position ptSputnik;
//   Position ptStarlink;
//   Position ptCrewDragon;
//   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   Position stars [50];

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
   

   double angleRadians; // get the radians for the degrees
   double gpsX; // get the GPS init X position
   double gpsY; // get the GPS init Y position
   double gravity = -9.8067; // the gravity is always pointing down
   double dx;
   double dy;
   double ddx;
   double ddy;
   double gpsHeight;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
//   if (pUI->isUp())
//      pDemo->ptShip.addPixelsY(1.0);
//   if (pUI->isDown())
//      pDemo->ptShip.addPixelsY(-1.0);
//   if (pUI->isLeft())
//      pDemo->ptShip.addPixelsX(-1.0);
//   if (pUI->isRight())
//      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += -(2.0 * M_PI / 30.0) * (1440.0 / 86400.0);
//   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   //Position pt;
   //ogstream gout(pt);

   //pGame->draw(&gout);

   //Physics physics;

   //pDemo->angleEarth -= physics.rotationSpeed();
   //pDemo->phaseStar++;


   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);/*
   //gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);*/
 /*  for (int i = 0; i < 50; i++)
   {
       gout.drawStar(pDemo->stars[i], pDemo->phaseStar);
   }*/

   // draw the earth

//   pt.setMeters(0.0, 0.0);
//   gout.drawEarth(pt, pDemo->angleEarth);
//
//   pDemo->angleRadians = physics.calculateRadius(pDemo->gpsX, pDemo->gpsY);
//
//   pDemo->ddx = physics.calculateDDX(-0.2244, pDemo->angleRadians);
//   pDemo->ddy = physics.calculateDDY(-0.2244, pDemo->angleRadians);
//
//   pDemo->dx = physics.calculateDX(pDemo->dx, pDemo->ddx, 30);
//   pDemo->dy = physics.calculateDY(pDemo->dy, pDemo->ddy, 30);
//
//   pDemo->gpsX = pDemo->gpsX + pDemo->dx * secPerFrame + 1 / 2 * pDemo->ddx * (pow(48, 2));
//   pDemo->gpsY = pDemo->gpsY + pDemo->dy * secPerFrame + 1 / 2 * pDemo->ddy * (pow(48, 2));
//
//   pDemo->ptGPS.setMeters(pDemo->gpsX, pDemo->gpsY);
//   gout.drawGPS(pDemo->ptGPS, pDemo->angleShip);

   
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Orbitor",   /* name on the window */
      ptUpperRight);


   Test test;
   test.testRunner();
   
   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &game);


   return 0;
}
