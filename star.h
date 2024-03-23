#pragma once
#include "position.h"
#include "uiDraw.h"

class Star
{
public:
	Star() {
		starTwinklePhase = random(0, 255);

		int posx = random(-1000, 1000);
		int posy = random(-1000, 1000);

		starPosition.setPixelsX(posx);
		starPosition.setPixelsY(posy);
	};
	void draw(ogstream* gout) {
		gout->drawStar(starPosition, starTwinklePhase++);
	};
private:
	Position starPosition;
	unsigned char starTwinklePhase;
};