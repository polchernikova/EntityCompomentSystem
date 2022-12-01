cmake_minimum_required(VERSION 3.23)
project(EntityCompomentSystem)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(engine, test)

add_executable(
        EntityCompomentSystem
        src/component_manager.cpp
        src/coordinator.cpp
        src/entity_manager.cpp
        src/system.cpp
        src/system_manager.cpp
        test/components.h
        test/systems/movement_system.cpp
        main.cpp
)
