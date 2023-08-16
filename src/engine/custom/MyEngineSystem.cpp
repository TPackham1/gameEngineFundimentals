#include "MyEngineSystem.h"

	
// enemy class that take in 2Point to allow the enemy to 'see' the player when it updates
// Enemy->Update is called when MyGame->Update is called, to keep them in sync

//FUNCTIONS
//Enemy::Enemy(Point2 startPos, int enemySpeed)
//{
//	debug("Enemy init");
//	pos = startPos; speed = enemySpeed;
//	
//}
//
//	
//
//		void Enemy::Update(const Point2& playerPos) {
//			// Calculate direction towards the player
//			float dx = playerPos.x - pos.x;
//			float dy = playerPos.y - pos.y;
//			float distance = sqrt(dx * dx + dy * dy);
//
//			// Normalize direction vector
//			if (distance != 0) {
//				dx /= distance;
//				dy /= distance;
//			}
//			//debug("Moving towards the player");
//			// Move towards the player
//		/*	pos.x += dx * speed;
//			pos.y += dy * speed;
//		*/
//
//
//		}







