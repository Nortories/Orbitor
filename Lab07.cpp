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

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <cmath>       // for MATH
#include <iomanip>
#include "physics.h"

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
//      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
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
   
   const double secPerFrame = 48; // 1 sec of simulation time is 48 sec of real time
   const double geoDistance = 42164000; // how far needs to be from the Earth
   double angleRadians; // get the radians for the degrees
   const double rEarth = 6378000 ; // the Earth radius
   double gpsX; // get the GPS init X position
   double gpsY; // get the GPS init Y position
   double gravity = -9.8067; // the gravity is always pointing down
   double heightGravity = -0.2244; // gravity for the GPS
   double geoSpeed = 3100;
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

   Position pt;
   ogstream gout(pt);

   // draw satellites
//   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
//   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

//   // draw parts
//   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
//   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
//   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
//   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
//   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set
//
//   // draw fragments
//   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);
//   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);
//
//   // draw a single star
   for (int i = 0; i < 50; i++)
   {
	  gout.drawStar(pDemo->stars[i], pDemo->phaseStar);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
   
   pDemo->angleRadians = calculateRadius(pDemo->gpsX, pDemo->gpsY);
   
   pDemo->ddx = calculateDDX(pDemo->heightGravity, pDemo->angleRadians);
   pDemo->ddy = calculateDDY(pDemo->heightGravity, pDemo->angleRadians);

   pDemo->dx = calculateDX(pDemo->dx, pDemo->ddx, SEC_PER_FRAME);
   pDemo->dy = calculateDY(pDemo->dy, pDemo->ddy, SEC_PER_FRAME);
   
   pDemo->gpsX = pDemo->gpsX + pDemo->dx * pDemo->secPerFrame + 1/2 * pDemo->ddx * (pow(pDemo->secPerFrame, 2));
   pDemo->gpsY = pDemo->gpsY + pDemo->dy * pDemo->secPerFrame + 1/2 * pDemo->ddy * (pow(pDemo->secPerFrame, 2));
   
   pDemo->ptGPS.setMeters(pDemo->gpsX, pDemo->gpsY);
   gout.drawGPS(pDemo->ptGPS, pDemo->angleShip);
   
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
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
