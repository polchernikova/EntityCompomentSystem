cmake_minimum_required(VERSION 3.23)
project(EntityCompomentSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(engine, test)

add_executable(
        EntityCompomentSystem
        engine/component_manager.cpp
        engine/coordinator.cpp
        engine/entity_manager.cpp
        engine/system.cpp
        engine/system_manager.cpp
        test/components.h
        test/systems/movement_system.cpp
        main.cpp
)
