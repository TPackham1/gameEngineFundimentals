#include "MyEngineSystem.h"
#include <string>
#include <cmath>
#include <random>

//#include "../GameMath.h"


enum class BehaviourStatus
{
	Success,
	Failure,
	Running
};

class Behaviour
{
public:
	virtual BehaviourStatus Execute() = 0;
};

class Sequence : public Behaviour
{
public:
	Sequence(const std::vector<Behaviour*>& Behaviours) : m_Behaviours(Behaviours) {}

	BehaviourStatus Execute() override {
		for (Behaviour* Behaviour : m_Behaviours) {
			BehaviourStatus status = Behaviour->Execute();
			if (status != BehaviourStatus::Success) {
				return status;
			}
		}
		return BehaviourStatus::Success;
	}

private:
	std::vector<Behaviour*> m_Behaviours;
};


class MoveToPlayer : public Behaviour
{
public:
	MoveToPlayer(MyEngineSystem* enemyBox) : m_Enemy(*enemyBox) {}

	BehaviourStatus Execute() override {

		if (IsPlayerInRange()) {
			// Player is already in range, no need to move
			return BehaviourStatus::Success;
		}

		// Move towards the player
		MoveTowardsPlayer();

		//  movement takes some time, returning 'Running' status
		return BehaviourStatus::Running;
	}
private:
	MyEngineSystem m_Enemy = new MyEngineSystem;

	bool IsPlayerInRange() {
		float distance = std::sqrt(m_Enemy.m_dx * m_Enemy.m_dx + m_Enemy.m_dy * m_Enemy.m_dy);
		if (distance <= m_Enemy.m_attackRange)
		{
			std::cout << "Tom Packham CI517 2022" << std::endl;
			return true;
		}
		else { return false; }
	}

	void MoveTowardsPlayer()
	{
		float distance = std::sqrt(m_Enemy.m_dx * m_Enemy.m_dx + m_Enemy.m_dy * m_Enemy.m_dy);
		float directionX = m_Enemy.m_dx / distance;
		float directionY = m_Enemy.m_dy / distance;
		m_Enemy.m_x += directionX * m_Enemy.m_speed;
		m_Enemy.m_y += directionY * m_Enemy.m_speed;
	}



};

//class AttackPlayer : public Behaviour {
//public:
//	BehaviourStatus Execute() override {
//		
//		return BehaviourStatus::Success;
//	}
//};


