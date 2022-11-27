#include <iostream>
#include <chrono>
#include "engine/coordinator.h"
#include "components.h"
#include "test/systems/movement_system.h"

int main(int argc, char** argv) {
    auto coordinator = std::make_unique<Coordinator>();

    // register all components
    coordinator->RegisterComponent<MotionComponent>();
    coordinator->RegisterComponent<TransformationComponent>();

    // register all systems (curently one)
    auto movementSystem = coordinator->RegisterSystem<MovementSystem>(coordinator.get());
    coordinator->SetSystemSignature<MovementSystem>(
            {coordinator->GetComponentType<MotionComponent>(),
             coordinator->GetComponentType<TransformationComponent>()});

    // create entities

    int entities_created = 100000;
    while(entities_created--) {
        Entity player = coordinator->CreateEntity();
        coordinator->AddComponent(player, TransformationComponent{});
        coordinator->AddComponent(player, MotionComponent{});
    }

    int iterations = 100;

    // immitate a tick of the game: call an update for all entities

    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i < iterations; i++) {
        movementSystem->Update();
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Average time for Update: " << elapsed.count() / iterations << std::endl;
}