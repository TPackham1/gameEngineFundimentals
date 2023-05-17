#include "MyEngineSystem.h"
#include <string>
#include <cmath>
#include <random>
#include "../GameMath.h"

enum class BehaviorStatus {
	Success,
	Failure,
	Running
};

class Behavior
{
	public:
		virtual BehaviorStatus Execute() = 0;
};

class Sequence : public Behavior {
public:
	Sequence(const std::vector<Behavior*>& behaviors) : m_Behaviors(behaviors) {}

	BehaviorStatus Execute() override {
		for (Behavior* behavior : m_Behaviors) {
			BehaviorStatus status = behavior->Execute();
			if (status != BehaviorStatus::Success) {
				return status;
			}
		}
		return BehaviorStatus::Success;
	}

private:
	std::vector<Behavior*> m_Behaviors;
};


class MoveToPlayer : public Behavior 
{
	public:
		MoveToPlayer(MyEngineSystem* enemy) : m_Enemy(*enemy) {}
		
	BehaviorStatus Execute() override {
		// Implement movement logic to move towards the player
		if (IsPlayerInRange()) {
			// Player is already in range, no need to move
			return BehaviorStatus::Success;
		}

		// Move towards the player
		MoveTowardsPlayer();

		// Assume the movement takes some time, so return Running status
		return BehaviorStatus::Running;
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
class AttackPlayer : public Behavior {
public:
	BehaviorStatus Execute() override {
		// Implement attack logic on the player
		return BehaviorStatus::Success;
	}
};


//ai contructor sets up the behaviour tree
MyEngineSystem::MyEngineSystem()
{
	Behavior* m_RootBehavior = nullptr;

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
	std::vector<Behavior*> sequenceBehaviors = { moveToPlayer , attackPlayer};


	Behavior* sequence = new Sequence(sequenceBehaviors);
	 m_RootBehavior = sequence;

};




// function to update the enemy instance
void MyEngineSystem::Update()
{
	// Execute the behavior tree
	BehaviorStatus status = m_RootBehavior->Execute();

	// Handle the behavior tree result if needed
	if (status == BehaviorStatus::Success)
	{
		// Behavior tree execution succeeded
	}
	else if (status == BehaviorStatus::Failure) {
		
	}
	else if (status == BehaviorStatus::Running) {
	}




};