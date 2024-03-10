#pragma once
#include "position.h"
#include "uiDraw.h"

class Star
{
	public :
		Star(){
			// Set stars to random positions
			Position ptUpperRight;
			for (int i = 0; i < NUMBER_OF_STARS; i++)
			{
				stars[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
				stars[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
				phaseStar[i] = random(0, 256);
			}
		}
		Star(Position ptUpperRight): _ptUpperRight(ptUpperRight) {
			// Set stars to random positionsq
			for (int i = 0; i < NUMBER_OF_STARS; i++)
			{
				stars[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
				stars[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
				phaseStar[i] = random(0, 256);
			}
		}

		void draw(ogstream *gout) {
			for (int i = 0; i < NUMBER_OF_STARS; i++)
			{
				gout->drawStar(stars[i], phaseStar[i]);
				phaseStar[i]++;
				if (phaseStar[i] > 260)
				{
					phaseStar[i] = 0;
				}
			}
		}

private:
		Position _ptUpperRight;
		Position stars[NUMBER_OF_STARS];
		unsigned char phaseStar[NUMBER_OF_STARS];
};