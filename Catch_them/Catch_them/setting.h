#pragma once

#include <stdlib.h>
namespace instruments {
	class Pos {
	public:
		float x = 0, y = 0;
		Pos(float aX, float aY) {
			x = aX, y = aY;
		}
		Pos() {

		}
	};
	static float random(float min, float max) {
		if (int(max - min) == 0) { return 0; }
		return (rand() % (int(max - min)) + min);
	}
}

namespace setting {
	static int WIDTH				= 640;
	static int HEIGHT				= 480;
	static int PLAYER_WIDTH			= 82;
	static int PLAYER_HEIGHT		= 113;
	static int MAX_NUM_OF_PRICES	= 5;
	static int SPAWN_LINE			= WIDTH - 100;
	static float SPEED_FALLING		= 1;
	static float SPEED				= 0.5;
	static instruments::Pos FIRST_PLAYER_POS(WIDTH / 2 - PLAYER_WIDTH / 2, HEIGHT - PLAYER_HEIGHT);
}