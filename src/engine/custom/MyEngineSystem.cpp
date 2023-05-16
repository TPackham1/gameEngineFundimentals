#include "MyEngineSystem.h"
#include <string>
#include <cmath>
#include <random>
#include "../GameMath.h"

	// EnemyAI construtor (dx(0),dy(0),attackrange,playerDead(check to see if the game state has changed))
		EnemyAI::EnemyAI(float dx, float dy,float attackRange,bool playerDead )
		{
			 m_x = getRandom(0,750)+1;
			 m_y = getRandom(0,550)+1;
			 m_dx = dx;
			 m_dy = dy;
			 m_speed = 2.5;
			 m_attackRange = attackRange;
			 m_playerDead = playerDead;
		};
	
		

	
	// function to update the enemy instance
	void EnemyAI::Update(float *playerX,float *playerY)
	{
		std::cout << "Moving to the player." << std::endl;
		EnemyAI::MoveToPlayer(playerX,playerY);
		
		


		
		
		
	};
	
	void EnemyAI::MoveToPlayer(float *playerX, float *playerY)
	{
		
		float distance = std::sqrt(m_dx * m_dx + m_dy * m_dy);
		if (distance <= m_attackRange)
		{
		}
		else
		{
			float directionX = m_dx / distance;
			float directionY = m_dy / distance;

			m_x += directionX * m_speed;
			m_y += directionY * m_speed;
			std::cout << "Enemy moves towards player." << std::endl;
		}



	};

	

	




