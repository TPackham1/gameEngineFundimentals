#include "MyEngineSystem.h"
#include <string>
#include <cmath>
#include <random>
#include "../GameMath.h"

enum class BehaviourStatus {
	Success,
	Failure,
	Running
};

class Behaviour
{
	public:
		virtual BehaviourStatus Execute() = 0;
};

class Sequence : public Behaviour {
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
		MoveToPlayer(MyEngineSystem* enemy) : m_Enemy(*enemy) {}
		
	BehaviourStatus Execute() override {
		
		if (IsPlayerInRange()) {
			// Player is already in range, no need to move
			return BehaviourStatus::Success;
		}

		// Move towards the player
		MoveTowardsPlayer();

		// Assume the movement takes some time, so return Running status
		return BehaviourStatus::Running;
	}
private:
	MyEngineSystem m_Enemy;

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
class AttackPlayer : public Behaviour {
public:
	BehaviourStatus Execute() override {
		
		return BehaviourStatus::Success;
	}
};


//ai contructor sets up the behaviour tree
MyEngineSystem::MyEngineSystem()
{
	Behaviour* m_RootBehaviour = nullptr;

	//m_player = player;
	m_x = getRandom(0, 750) + 1;
	m_y = getRandom(0, 550) + 1;
	m_dx = 0;
	m_dy = 0;
	m_speed = 2.5;
	m_attackRange = 0.1;
	m_playerDead = false;


	
	//setting up behaviours
	MoveToPlayer* moveToPlayer = new MoveToPlayer(this);
	AttackPlayer* attackPlayer = new AttackPlayer();
	std::vector<Behaviour*> sequenceBehaviours = { moveToPlayer , attackPlayer};


	Behaviour* sequence = new Sequence(sequenceBehaviours);
	 *m_RootBehaviour = *sequence;

};




// function to update the enemy instance
void MyEngineSystem::Update()
{
	// Execute the Behaviour tree
	BehaviourStatus status = m_RootBehaviour->Execute();

	// Handle the Behaviour tree result if needed
	if (status == BehaviourStatus::Success)
	{
		// Behaviour tree execution succeeded
	}
	else if (status == BehaviourStatus::Failure) {
		
	}
	else if (status == BehaviourStatus::Running) {
	}




};