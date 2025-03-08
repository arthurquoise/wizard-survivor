#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    int hp;
    int xp;
    float speed;
    Vector2 pos;
} Player;

void InitPlayer(Player* player);
void UpdatePlayer(Player* player);
void DrawPlayer(Player* player);

static void UpdateMovement(Player* player);

#endif