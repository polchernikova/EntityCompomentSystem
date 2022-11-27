#include "movement_system.h"

#include "components.h"
#include <iostream>
#include <ctime>

MovementSystem::MovementSystem(Coordinator *coordinator) :
        coordinator_(coordinator) {}

void MovementSystem::Update() {
    for (const auto &entity: entities_) {
        // std::cout << "Update" << std::endl; // if we want to check if the function is called
        auto &motion = coordinator_->GetComponent<MotionComponent>(entity);
        auto &transform =
                coordinator_->GetComponent<TransformationComponent>(entity);
        transform.position = transform.position + motion.direction * motion.current_speed;
    }
}
