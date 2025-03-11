
#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

typedef enum {
    MOVE_NONE  = 0,
    MOVE_UP    = 1 << 0,
    MOVE_DOWN  = 1 << 1,
    MOVE_LEFT  = 1 << 2,
    MOVE_RIGHT = 1 << 3
} PlayerMovement;

PlayerMovement GetPlayerMovement()
{
    PlayerMovement dir = MOVE_NONE;

    if (IsKeyDown(KEY_W)) dir |= MOVE_UP;
    if (IsKeyDown(KEY_S)) dir |= MOVE_DOWN;
    if (IsKeyDown(KEY_A)) dir |= MOVE_LEFT;
    if (IsKeyDown(KEY_D)) dir |= MOVE_RIGHT;

    return dir;
}

#endif