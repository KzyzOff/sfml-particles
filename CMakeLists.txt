cmake_minimum_required(VERSION 3.1)
project(sfml_particles)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif (UNIX)

if (WIN32)
    set ( SFML_STATIC_LIBRARIES TRUE )
    # set(CMAKE_EXE_LINKER_FLAGS "-static")
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "E:/cpp/SFML-2.5.1/lib/cmake/SFML")
endif (WIN32)

find_package(SFML 2 COMPONENTS window system graphics REQUIRED)

add_executable(sfml_particles
        main.cpp
        Particles.h Particles.cpp)

target_link_libraries(sfml_particles sfml-graphics sfml-audio)