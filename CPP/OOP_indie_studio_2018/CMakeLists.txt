cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2018)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE 
	src/main.cpp
	src/Display.cpp
	src/EventReceiver.cpp
	src/CubeNode.cpp
	src/Player/PlayerNode.cpp
	src/Player/APlayerNode.cpp
	src/Player/AINode.cpp
	src/Player/Moves.cpp
	src/MapGenerator.cpp
	src/Games/AGameMode.cpp
	src/Games/LoadMap.cpp
	src/Games/BattleRoyale.cpp
	src/Games/TwoVsTwo.cpp
	src/Games/Spectator.cpp
	src/BombNode.cpp
	src/ExplosionAnimator.cpp
	src/Sfx.cpp
	src/Intro.cpp
	src/FindCollision.cpp
	src/PowerUpNode.cpp
)

if (UNIX) 
	file(COPY /usr/include/irrlicht DESTINATION "../include/")
	file(COPY /usr/include/SFML/Audio.hpp DESTINATION "../include/SFML/Audio/.")
	# file(COPY /usr/include/SFML/Audio/SoundBuffer.hpp DESTINATION "../include/SFML/Audio/.")
	include_directories("../include/")
	add_executable(bomberman ${SOURCE})
	target_link_libraries(bomberman Irrlicht sfml-audio)
endif(UNIX)

if (WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
	# find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
	# if (SFML_FOUND)
		# include_directories(${SFML_INCLUDE_DIR})
	# endif()
	file(COPY C:/irrlicht/include/irrlicht DESTINATION "../include/")
	file(COPY C:/irrlicht/bin/Win32-VisualStudio/Irrlicht.dll DESTINATION "Debug/")
	# file(COPY "C:/Program Files (x86)/SFML/include/SFML" DESTINATION "../include/.")
	# file(COPY "C:/Program Files (x86)/SFML/include/SFML/Audio.hpp" DESTINATION "../include/SFML/Audio/.")
	include_directories("../include/irrlicht")
	# include_directories("../include/SFML")
	add_executable(bomberman ${SOURCE})
	target_link_libraries(bomberman "C:/irrlicht/lib/Win32-visualstudio/Irrlicht.lib")
	# target_link_libraries(bomberman "C:/irrlicht/lib/Win32-visualstudio/Irrlicht.lib" "C:/SFML/lib/sfml-graphics.lib" "C:/SFML/lib/sfml-window.lib" "C:/SFML/lib/sfml-audio.lib" "C:/SFML/lib/sfml-system.lib")
	# target_link_libraries(bomberman "C:/irrlicht/lib/Win32-visualstudio/Irrlicht.lib" ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif(WIN32)
