cmake_minimum_required(VERSION 3.12)
project(master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(master
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/master.cbp
        cmake-build-debug/rich
        CMakeLists.txt
        command.c
        command.h
        init_players.c
        init_players.h
        land_trade.c
        land_trade.h
        main.c
        preset.c
        preset.h
        map.c
        map.h
        rich.c
        rich.h
        walk.c
        walk.h
		gift.c
		gift.h
		site.c
		site.h
		tool.c
		tool.h)
