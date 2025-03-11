#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include "raylib.h"

#include "input.h"

typedef struct {
    int hp;
    int xp;
    float speed;
    Vector2 pos;
} Player;

Player* InitPlayer();
void UpdatePlayer(Player* player);
void DrawPlayer(Player* player);
void DestroyPlayer(Player* player);

static void UpdateMovement(Player* player);

#endif