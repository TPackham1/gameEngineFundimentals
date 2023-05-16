#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"

	
class EnemyAI
	{
		friend class XCube2Engine;


		public:
			EnemyAI(float dx, float dy, float attackRange, bool playerDead); EnemyAI();
			void Update(float *playerX,float *playerY);
			void MoveToPlayer(float *playerX,float *playerY);
			
		private:
			float m_x;
			float m_y;
			float m_speed;
			float m_dx;
			float m_dy;
			float m_attackRange;
			bool m_playerDead;
	};



#endif