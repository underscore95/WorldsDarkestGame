# CMakeList.txt : CMake project for WorldsDarkestGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("WorldsDarkestGame")

include(C:/libs/vcpkg-master/scripts/buildsystems/vcpkg.cmake)

add_executable (WorldsDarkestGame "src/Game.cpp" "src/GameObject.h"  "src/Game.h" "src/Scene.h" "src/Scene.cpp" "src/Game/GameScene.h" "src/Game/GameScene.cpp" "src/Game/Player.h" "src/Game/Player.cpp" "src/Utils/Math.h"   "src/Game/Wall.h" "src/Game/Wall.cpp" "src/GameObject.cpp" "src/Game/Levels/Level.h" "src/Game/Levels/Level0.h" "src/Game/Levels/Level.cpp" "src/Game/Light.h"  "src/Game/enemies/Enemy.h"  "src/Game/enemies/PathEnemy.h" "src/GameOverScene.h" "src/GameOverScene.cpp" "src/Game/Goal.h" "src/Game/Levels/Level1.h" "src/Game/Levels/Level2.h" "src/Game/Levels/Level3.h" "src/Game/Portal.h" "src/Game/Portal.cpp" "src/Game/Levels/Level4.h" "src/Game/Door.h" "src/Game/Door.cpp" "src/Game/Key.h" "src/Game/Key.cpp")

find_package(raylib CONFIG REQUIRED)
target_link_libraries(WorldsDarkestGame PRIVATE raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET WorldsDarkestGame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
