#include "simulation.h"

void Simulation::input(const Interface* pUI)
{
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
}

void Simulation::updateFrame()
{
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

           if (obj1->isHit(obj2))
           {
               deleteList.push_back(obj1);
               deleteList.push_back(obj2);
           }
           if (obj2->crashedOnEarth())
           {
               deleteList.push_back(obj2);
           }
       }

       // Check ships collisions also
       if (starShip != nullptr) {
           if (starShip->isDead() == false) {

               if (starShip->isHit(*object1))
               {
                   deleteList.push_back(*object1);
                   starShip->triggerDestruction();
               }

               if (starShip->crashedOnEarth()) // TODO: If there is only one object in the Sim list this will never trigger. Josh S March 22,2024
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
}

void Simulation::draw(ogstream* gout)
{
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
}

Simulation::Simulation(Position ptUpperRight)
{
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
   starShip = new StarShipEnterprise();

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

   Hubble* hubble = new Hubble();
   objects.push_back(hubble);

   /*******************************
   /*  Create Crew Dragon
   /******************************/

   Dragon* dragon = new Dragon();
   objects.push_back(dragon);

   /*******************************
   /*  Create StarLink satellite.
   /******************************/

   StarLink* starLink = new StarLink();
   objects.push_back(starLink);
}
