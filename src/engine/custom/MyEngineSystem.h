#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"
#include "MyEngineSystem.cpp"
using namespace std;

class Behvior;

class MySytemEngine
	{
		friend class XCube2Engine;


		public:
			MySytemEngine(float dx, float dy, float attackRange, bool playerDead);
			void Update();
			float m_speed;
			float m_dx;
			float m_dy;
			float m_x;
			float m_y;
			float m_attackRange;
			Behavior* m_RootBehavior;
			
		private:
			//Rect m_player;
			
			
			
			bool m_playerDead;
	};



#endif