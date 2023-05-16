#include "MyEngineSystem.h"
#include <string>
#include <random>
#include <cmath>
#include "../../demo/MyGame.h"
class Enemy


{
	private:
		float x;
		float y;
		float speed;
		float ar;
		bool playerDead;
	
	public:
		 Enemy(float startingX, float startingY, float enemySpeed, float range)
			: x(startingX), y(startingY), speed(enemySpeed), ar(range) {};

	
		//void Init(int width,int height)
		//{
			//std::cout << "mySystem init\n";
		
			//x = StartingPos(width);
			//y = StartingPos(height);
			//speed = 2.5;
			//ar = 0.1;
			//playerDead = false;


		//}

	//enemy init
	/*Enemy(float startingX, float startingY, float enemySpeed, float range, bool playerIsAlive)
		: x(startingX), y(startingY), speed(enemySpeed), ar(range), playerDead(playerIsAlive) {}*/


	// used twice to generate a starting posision for the enemy location
	float StartingPos(int &max)
	{
		float n;
		n = (rand() % max) + 1;
		return n;
	}

	void MoveToPlayer(const Player& p)
	{
		if (playerDead != false)
		{
		}
		else
		{
			float dx = p.GetPlayerX - x;
			float dy = p.GetPlayerY - y;

			//calculate distance from player to this enemy
			float distance = std::sqrt(dx * dx + dy * dy);

			if (distance <= ar)
			{
				std::cout << "Enemy attack player" << std::endl;
			}
			else
			{
				float directionX = dx / distance;
				float directionY = dy / distance;

				x += directionX * speed;
				y += directionY * speed;

				std::cout << "Moving to the player." << std::endl;
				std::cout << "New Pos:(" << x << ", " << y << ")" << std::endl;
			}
		}
	
	}


};
class Player {
private:
	float playerX;
	float playerY;
public:
	Player(float playerStartX, float playerStartY) : playerX(playerStartX), playerY(playerStartY) {}
	float GetPlayerX() const { return playerX; }
	float GetPlayerY() const { return playerY; }
};