#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__
#include "../engine/custom/MyEngineSystem.h"
#include "../engine/AbstractGame.h"



struct GameKey {
	Point2 pos;
	bool isAlive;
};

class MyGame : public AbstractGame {
private:
	MySytemEngine enemy;
	Rect box;
	Rect enemyBox;
	float playerX;
	float PlayerY;
	Vector2i velocity;

	std::vector<std::shared_ptr<GameKey>> gameKeys;

	/* GAMEPLAY */
	int score, numKeys, lives;
	bool gameWon;

	void handleKeyEvents();
	void update();
	void render();
	void renderUI();
	public:
        MyGame();
		~MyGame();
};
#endif

