#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include "../EngineCommon.h"
#include "MyEngineSystem.cpp"
using namespace std;


class MyEngineSystem
	{
		friend class XCube2Engine;


		public:
			MyEngineSystem();
			void Update();
			float m_speed;
			float m_dx;
			float m_dy;
			float m_x;
			float m_y;
			float m_attackRange;
			Behaviour* m_RootBehaviour;
			
		private:
			//Rect m_player;
			
			
			
			bool m_playerDead;
	};



#endif