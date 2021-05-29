cmake_minimum_required(VERSION 3.19)
project(LABO04)

set(CMAKE_CXX_STANDARD 14)

add_executable(LABO04 main.cpp Field.cpp Field.h Humanoid/Humanoid.cpp Humanoid/Humanoid.h GUI/Display.cpp GUI/Display.h Humanoid/Human.cpp Humanoid/Human.h Humanoid/Vampire.cpp Humanoid/Vampire.h Humanoid/Buffy.cpp Humanoid/Buffy.h Action/Action.h Action/Move.cpp Action/Move.h Position/Position.cpp Position/Position.h Position/Movement.cpp Position/Movement.h Position/Offset.cpp Position/Offset.h Action/Action.cpp Action/Kill.cpp Action/Kill.h Action/Transform.cpp Action/Transform.h Utils.cpp Utils.h SIM/Simulation.cpp SIM/Simulation.h)