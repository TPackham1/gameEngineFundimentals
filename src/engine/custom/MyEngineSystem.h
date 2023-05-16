#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"

	
class EnemyAI
	{
		friend class XCube2Engine;


		public:
			EnemyAI(float dx, float dy, float attackRange, bool playerDead); 
			void Update();
			float m_speed;
			float m_dx;
			float m_dy;
			float m_x;
			float m_y;
			
		private:
			//Rect m_player;
			
			Behavior* m_RootBehavior;
			float m_attackRange;
			bool m_playerDead;
	};



#endif