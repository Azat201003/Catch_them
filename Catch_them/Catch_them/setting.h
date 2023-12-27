#pragma once
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
}

namespace setting {
	static int WIDTH			= 640;
	static int HEIGHT			= 480;
	static int PLAYER_WIDTH		= 50;
	static int PLAYER_HEIGHT	= 50;
	static float SPEED			= 20;
	static instruments::Pos FIRST_PLAYER_POS(WIDTH / 2 - PLAYER_WIDTH / 2, HEIGHT - PLAYER_HEIGHT);
}