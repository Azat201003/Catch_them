#pragma once

#include <stdlib.h>
#include <chrono>
namespace instruments {
	enum window {
		game,
		menu,
		settings
	};
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
	static int PLAYER_HEIGHT		= 98;
	static int MAX_NUM_OF_PRICES	= 4;
	static int SPAWN_LINE			= HEIGHT - 250;
	static int HP					= 10;
	static float SPEED_FALLING		= 2 * 0.0001;
	static float SPEED_PLAYER		= 5 * 0.0001;
	static float LEN_COINS			= 100;
	static float LEN_HP				= 250;
	static instruments::Pos FIRST_PLAYER_POS(WIDTH / 2 - PLAYER_WIDTH / 2, HEIGHT - PLAYER_HEIGHT);
}