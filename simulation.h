#pragma once

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
#include "hubble.h"
#include "dragon.h"
#include "starLink.h"


class Simulation {
public:
    /*************************************************************
    /*  Init the simulation with the ship stars and satellites.
    /*************************************************************/
    Simulation(Position ptUpperRight);

    void draw(ogstream* gout);

    void updateFrame();

    // Handle the input for the crew dragon.
    void input(const Interface* pUI);

private:
    // Array of satellites in the simulation.
    list<Object*> objects;
    // Array of background stars in the simulation.
    list<Star*> stars;
    // The main ship controlled by the user in the simulation.
    StarShipEnterprise* starShip;
    Earth* earth;
};
