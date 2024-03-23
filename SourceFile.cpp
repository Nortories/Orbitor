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

#define _USE_MATH_DEFINES // for cmath's M_PI
#include <cmath>       // for MATH
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"
#include "position.h"      // for POINT
#include <iomanip>
#include "config.h"
#include "test.h"
#include "star.h"
#include "object.h"
#include "starShipEnterprise.h"
#include "Earth.h"
#include "bullet.h"
#include "sputnik.h"
#include "fragment.h"
#include "gps.h"


using namespace std;

class Simulation {
public:
    /*************************************************************
    /*  Init the simulation with the ship stars and satellites.
    /*************************************************************/
    Simulation(Position ptUpperRight) {

        /*******************************
        /*  Create the stars.
        /******************************/
        for (int i = 0; i < STARS; i++)
        {
            // init new star
            Star* newStar = new Star();
            // add to list of stars
            stars.push_back(newStar);
        }

        /*******************************
        /*  Create Earth.
        /******************************/
		earth = new Earth();

        /*******************************
        /*  Create StarShipEnterprise.
        /******************************/

        Angle ang(0);
        Velocity vel(0, ang);
        Position pos(USER_STARTIN_POSITION, USER_STARTIN_POSITION);
        starShip = new StarShipEnterprise(vel, pos, ang, 0);

        /*******************************
        /*  Create Sputnik!
        /******************************/

        Sputnik* sputnik = new Sputnik();
        objects.push_back(sputnik);

        /*******************************
        /*  Create the 6 GPS satellites.
        /******************************/
        GPS* gps1 = new GPS(GPS1_POSITION_X, GPS1_POSITION_Y, GPS1_VECTOR_X, GPS1_VECTOR_Y);
        GPS* gps2 = new GPS(GPS2_POSITION_X, GPS2_POSITION_Y, GPS2_VECTOR_X, GPS2_VECTOR_Y);
        GPS* gps3 = new GPS(GPS3_POSITION_X, GPS3_POSITION_Y, GPS3_VECTOR_X, GPS3_VECTOR_Y);
        GPS* gps4 = new GPS(GPS4_POSITION_X, GPS4_POSITION_Y, GPS4_VECTOR_X, GPS4_VECTOR_Y);
        GPS* gps5 = new GPS(GPS5_POSITION_X, GPS5_POSITION_Y, GPS5_VECTOR_X, GPS5_VECTOR_Y);
        GPS* gps6 = new GPS(GPS6_POSITION_X, GPS6_POSITION_Y, GPS6_VECTOR_X, GPS6_VECTOR_Y);

        objects.push_back(gps1);
        objects.push_back(gps2);
        objects.push_back(gps3);
        objects.push_back(gps4);
        objects.push_back(gps5);
        objects.push_back(gps6);

        /*******************************
        /*  Create the Hubble telescope.
        /******************************/

        /*******************************
        /*  Create StarLink satellite.
        /******************************/

    };

    void draw(ogstream* gout) {
        // Draw the stars
        for (auto& star : stars) {
            star->draw(gout);
        };

        earth->draw(gout);

        // Draw the objects from the list
        for (auto& object : objects) {
            object->draw(gout);
        };

        // Dont draw the ship if it is dead.
        if (starShip != nullptr)
        {
            starShip->draw(gout);
        }

    };

    void updateFrame() {
        list<Object*> deleteList;

        if (starShip != nullptr)
        {
            starShip->flyShip();
        }
        // Move the satellites
        for (auto& object : objects) {
            object->updatePosition();
            if (object->isDead()) {
                deleteList.push_back(object);
            }
        };

        // Collisions
        for (auto object1 = objects.begin(); object1 != objects.end(); object1++) 
        {
            for (auto object2 = std::next(object1); object2 != objects.end(); object2++)
            {
                auto& obj1 = *object1;
                auto& obj2 = *object2;

                if (obj1->hit(obj2))
                {
                    deleteList.push_back(obj1);
                    deleteList.push_back(obj2);
                }
                if (obj2->crashOnEarth())
                {
                    deleteList.push_back(obj2);
                }
            }

            // Check ships collisions also
            if (starShip != nullptr) {
                if (starShip->isDead() == false) {

                    if (starShip->hit(*object1))
                    {
                        deleteList.push_back(*object1);
                            starShip->triggerDestruction();
                    }

                    if (starShip->crashOnEarth()) // TODO: If there is only one object in the Sim list this will never trigger. Josh S March 22,2024
                    {
                        cout << "Ship has crashed on Earth" << endl;
                        starShip->triggerDestruction();
                    }
                }
            }
        }

        // Remove dead satellites.
        for (auto& obj : deleteList) {

            obj->explode(&objects);
            cout << "HIT a Object" << endl;
            objects.remove(obj);
        }

        if (starShip != nullptr)
        {
            if (starShip->isDead())
            {
                cout << "The Enterprize has Exploded!!" << endl;
                starShip->explode(&objects);
                delete starShip;
                starShip = nullptr;
            }
        }
    };


    // Handle the input for the crew dragon.
    void input(const Interface* pUI) {

        if (starShip != nullptr)
        {
            if (pUI->isDown())
            {
                starShip->setThrust(true);
            }
            else
            {
                starShip->setThrust(false);
            }
            if (pUI->isLeft())
            {
                starShip->rotateLeft();
            }
            if (pUI->isRight())
            {
                cout << "right" << endl;
                starShip->rotateRight();
            }
            if (pUI->isSpace())
            {
                Bullet* newBullet = starShip->fire();
                objects.push_back(newBullet);
            }
        }
    };

private:
    // Array of satellites in the simulation.
    list<Object*> objects;
    // Array of background stars in the simulation.
    list<Star*> stars;
    // The main ship controlled by the user in the simulation.
    StarShipEnterprise* starShip;
    Earth* earth;
};


// The callback function for the simulation handles the calls for input, move, and draw for each frame
void callBack(const Interface* pUI, void* p)
{
    Simulation* pSimulation = (Simulation*)p;
    ogstream* gout = new ogstream();

    pSimulation->input(pUI);
    pSimulation->updateFrame();
    pSimulation->draw(gout);

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
    
    /******************************************
    /* Run the tests
    /*******************************************/

     //testRunner();
    
    /*******************************************/


    // Set the upper window position and size
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1900.0);
    ptUpperRight.setPixelsY(1050);

    // Initialize the interface
    Interface ui(0, NULL, "Orbitor Simulator", ptUpperRight);

    // Initialize the sim
    Simulation sim(ptUpperRight);

    /***********************************************************************************
    /* Set everything into action by passing in the simulation and the callback function
    /* to the interface. This will start the simulation, and the callback function will
    /* be called for each frame.
    /***********************************************************************************/
    ui.run(callBack, &sim);

   return 0;
}
