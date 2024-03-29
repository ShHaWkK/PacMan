cmake_minimum_required(VERSION 3.23)
project(PacMan C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

###                                                             SDL                                                                ###

set(SDL2_PATH "C:/C_libraries/SDL2-2.28.5/x86_64-w64-mingw32")

###                                                             SDL_ttf                                                                ###
set(SDL2_TTF_PATH "C:/C_libraries/SDL2_ttf-2.20.2/x86_64-w64-mingw32")
set(SDL2_TTF_INCLUDE_DIR "C:/C_libraries/SDL2_ttf-2.20.2/x86_64-w64-mingw32/include")
set(SDL2_TTF_LIBRARY "C:/C_libraries/SDL2_ttf-2.20.2/x86_64-w64-mingw32/lib/libSDL2_ttf.dll.a")
###                                                             SDL_mixer                                                                ###
set(SDL2_MIXER_PATH "C:/C_libraries/SDL2_mixer-2.6.3/x86_64-w64-mingw32")
set(SDL2_MIXER_INCLUDE_DIR "C:/C_libraries/SDL2_mixer-2.6.3/x86_64-w64-mingw32/include")
set(SDL2_MIXER_LIBRARIES "C:/C_libraries/SDL2_mixer-2.6.3/x86_64-w64-mingw32/lib/libSDL2_mixer.dll.a")
###                                                             SDL_image                                                                ###

set(SDL2_IMAGE_PATH "C:/C_libraries/SDL2_image-2.8.2/x86_64-w64-mingw32")
set(SDL2_IMAGE_INCLUDE_DIR "C:/C_libraries/SDL2_image-2.8.2/x86_64-w64-mingw32/include")
set(SDL2_IMAGE_LIBRARY "C:/C_libraries/SDL2_image-2.8.2/x86_64-w64-mingw32/lib/libSDL2_image.dll.a")


find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

### Include directories ###
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} )
add_executable(PacMan
        src/main.c
        src/map.c
        src/game.c
        src/pacman.c
        src/map.c
        src/mouse.c

        include/game.h
        include/ghost.h
        include/map.h
        include/pacman.h
        include/mouse.h

        assets/textures
        assets/sounds


        )

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
