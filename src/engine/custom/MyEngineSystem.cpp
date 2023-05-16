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
		MoveToPlayer(EnemyAI* enemy) : m_Enemy(enemy) {}

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
	EnemyAI* m_Enemy;

	bool IsPlayerInRange() {
		return false;

	}

	void MoveTowardsPlayer() 
	{
		float distance = std::sqrt(m_Enemy->m_dx * m_Enemy->m_dx + m_Enemy->m_dy * m_Enemy->m_dy);
		float directionX = m_Enemy->m_dx / distance;
		float directionY = m_Enemy->m_dy / distance;
		m_Enemy->m_x += directionX * m_Enemy->m_speed;
		m_Enemy->m_y += directionY * m_Enemy->m_speed;
	}

	class AttackPlayer : public Behavior {
	public:
		BehaviorStatus Execute() override {
			// Implement attack logic on the player
			return BehaviorStatus::Success;
		}
	};
	
};	

	/*void EnemyAI::LogicMoveToPlayer(float *playerX, float *playerY)
	{

		float distance = std::sqrt(m_dx * m_dx + m_dy * m_dy);
		if (distance <= m_attackRange)
		{
			float directionX = m_dx / distance;
			float directionY = m_dy / distance;

			m_x += directionX * m_speed;
			m_y += directionY * m_speed;
			std::cout << "Enemy moves towards player." << std::endl;
			std::cout << "New position: (" << m_x << ", " << m_y << ")" << std::endl;
		}
		else
		{
			float directionX = m_dx / distance;
			float directionY = m_dy / distance;

			m_x += directionX * m_speed;
			m_y += directionY * m_speed;
			std::cout << "Enemy moves towards player." << std::endl;
			std::cout << "New position: (" << m_x << ", " << m_y << ")" << std::endl;
		}



	};*/

//ai contructor & sets up the behaviour tree
EnemyAI::EnemyAI(float dx, float dy, float attackRange, bool playerDead)
{
	//m_player = player;
	m_x = getRandom(0, 750) + 1;
	m_y = getRandom(0, 550) + 1;
	m_dx = dx;
	m_dy = dy;
	m_speed = 2.5;
	m_attackRange = attackRange;
	m_playerDead = playerDead;


	
	//setting up behaviours
	MoveToPlayer* moveToPlayer = new MoveToPlayer(this);
	//Behavior* attackPlayer = new AttackPlayer(this);
	std::vector<Behavior*> sequenceBehaviors = { moveToPlayer };


	Behavior* sequence = new Sequence(sequenceBehaviors);
	 m_RootBehavior = sequence;

};




// function to update the enemy instance
void EnemyAI::Update()
{
	// Execute the behavior tree
	BehaviorStatus status = m_RootBehavior->Execute();

	// Handle the behavior tree result if needed
	// For example, you can check the status and perform actions accordingly
	if (status == BehaviorStatus::Success) {
		// Behavior tree execution succeeded
	}
	else if (status == BehaviorStatus::Failure) {
		// Behavior tree execution failed
	}
	else if (status == BehaviorStatus::Running) {
		// Behavior tree execution is still ongoing
	}




};