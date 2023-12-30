#pragma once

#include <stdlib.h>
#include <chrono>
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
		if (int(max - min) == 0) { return max; }
		auto t = std::chrono::steady_clock::now();
		srand(std::chrono::duration_cast<std::chrono::microseconds>(t.time_since_epoch()).count());
		return (rand() % (int(max - min) + 1) + min);
	}
}

namespace setting {
	static int WIDTH				= 640;
	static int HEIGHT				= 480;
	static int PLAYER_WIDTH			= 82;
	static int PLAYER_HEIGHT		= 113;
	static int MAX_NUM_OF_PRICES	= 5;
	static int SPAWN_LINE			= HEIGHT - 100;
	static float SPEED_FALLING		= 1;
	static float SPEED_PLAYER		= 0.7;
	static float LEN_COINS			= 100;
	static instruments::Pos FIRST_PLAYER_POS(WIDTH / 2 - PLAYER_WIDTH / 2, HEIGHT - PLAYER_HEIGHT);
}