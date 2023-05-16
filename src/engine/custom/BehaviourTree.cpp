#include "MyEngineSystem.h"

enum class BehaviorStatus {
    Success,
    Failure,
    Running
};

class Behavior {
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

class MoveToPlayer : public Behavior {
public:
    BehaviorStatus Execute() override {
        // Implement movement logic to move towards the player
        return BehaviorStatus::Success;
    }
};

class AttackPlayer : public Behavior {
public:
    BehaviorStatus Execute() override {
        // Implement attack logic on the player
        return BehaviorStatus::Success;
    }
};

Enemy::Enemy() {
   
    Behavior* moveToPlayer = new MoveToPlayer();
    Behavior* attackPlayer = new AttackPlayer();

    // Create a sequence behavior that executes behaviors in order
    std::vector<Behavior*> sequenceBehaviors = { moveToPlayer, attackPlayer };
    Behavior* sequence = new Sequence(sequenceBehaviors);

    
    m_RootBehavior = sequence;
}

void Enemy::Update() {
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
}
