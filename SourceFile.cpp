/*************************************************************
 * 1. Name:
 *      Josh and Kai
 * 2. Assignment Name:
 *      Orbit Simulator
 * 3. Assignment Description:
 *      This simulator will simulate the movement of satellites and stars in space
 *      around the Earth. The user will be able to control a spaceship and fly it
 *      around the screen. The simulator will also simulate the movement of the
 *      satellites and stars in the background.
 *      The User will be able to control the spaceship with the arrow keys and the
 *      space bar to fire bullets.
 *****************************************************************/


#include "simulation.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "position.h"


using namespace std;

// The callback function for the simulation handles the calls for input, move, and draw for each frame
void callBack(const Interface* pUI, void* p)
{
    Simulation* pSimulation = (Simulation*)p;
    ogstream* gout = new ogstream();

    pSimulation->input(pUI);
    pSimulation->updateFrame();
    pSimulation->draw(gout);

}

    // The meters from pixels conversion factor
    double Position::metersFromPixels = 40.0;

int main(int argc, char** argv)
{
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1900.0);
    ptUpperRight.setPixelsY(1050);
    Interface ui(0, NULL, "Orbitor Simulator", ptUpperRight);
    Simulation sim(ptUpperRight);
    ui.run(callBack, &sim);
   return 0;
}
