#include "bullet.h"

void Bullet::draw(ogstream* gout)
{
   gout->drawProjectile(position);

   range--;
   if (range <= 0)
   {
      triggerDestruction();
   }
}
