#ifndef GAMEDEF_H
#define GAMEDEF_H
#include <glm/glm.hpp>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#define TILE_WIDTH 10
#define TILE_HEIGHT 10
#define TILE_DEPTH 10

#define GRAVITY 0.5f
#define MOVEMENT_SPEED 0.5f
#define JUMP_STRENGTH 4.6f

#define INVU_TIME 2.0f
#define STARTING_HITPOINTS 2

#define LEFT 0
#define RIGHT 1

#define GAME_FAILURE 0
#define GAME_ACTIVE 1
#define GAME_BEAT 2

#define EMPTY_SPACE 0
#define BASIC_TILE 1
#define PLAYER -1
#define ENDPOINT -2
#define SPIKES -3




#endif //GAMEDEF_H