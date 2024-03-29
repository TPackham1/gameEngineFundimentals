#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"
#include "../engine/custom/MyEngineSystem.h"

struct GameKey {
	Point2 pos;
	bool isAlive;
};

	class Enemy
	{
	public:

		Enemy(Point2 startPos, int enemySpeed);
		void Update(const Point2& playerPos);
	Point2 pos;
		/*float GetPosX();
		float GetPosY();*/
	private:
	//	float enemyHP;
		int speed;
	};

class MyGame : public AbstractGame {
	private:
		Rect box; //player
		//float playerHP;
		Vector2i velocity;

		std::vector<std::shared_ptr<GameKey>> gameKeys;
		
		 
		Point2 playerPosition; // Store player position

		/* GAMEPLAY */
		int score, numKeys, lives;

		bool gameWon;
		bool gameLost;

		Enemy enemy;
		void handleKeyEvents();
		void update();
		void render();
		void renderUI();
	public:
        MyGame();
		~MyGame();
};


#endif // __TEST_GAME_H__