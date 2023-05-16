#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"
#include "MyEngineSystem.cpp" 

class Enemy
{
	friend class XCube2Engine; 
	float StartingPos(int) {};
	private:
		float x;
		float y;
		float ar;
		float speed;
		
	public:
		Enemy(float startX , float startY, float setSpeed, float attackRange,bool playerDead) 
		:x(startX),y(startY),speed(setSpeed), ar(attackRange)	{};
		void MoveToPlayer(const Player&){};
};

#endif
class Player {
private:
	float playerX;
	float playerY;
public:
	Player(float playerStartX, float playerStartY)
		: playerX(playerStartX), playerY(playerStartY) {}
	float GetPlayerX() const { return playerX; }
	float GetPlayerY() const { return playerY; }
};