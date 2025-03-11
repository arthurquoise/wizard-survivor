#include "player.h"

Player* InitPlayer()
{
    Player* player = (Player*)malloc(sizeof(Player));
    if(player == NULL)
    {
        TraceLog(LOG_INFO, "Unable to allocate memory for Player!");
    }

    player->hp = 100;
    player->pos = (Vector2) {0.0f, 0.0f};
    player->speed = 2.0f;
    player->xp = 0;

    return player;
}

void UpdatePlayer(Player* player)
{
    UpdateMovement(player);
}

void DrawPlayer(Player* player)
{
    DrawRectangle(player->pos.x, player->pos.y, 32, 32, GREEN);
}

void DestroyPlayer(Player* player)
{
    free(player);
}

static void UpdateMovement(Player* player)
{
    PlayerMovement dir = GetPlayerMovement();
    Vector2 move = {0};

    if (dir & MOVE_UP)    move.y -= 1;
    if (dir & MOVE_DOWN)  move.y += 1;
    if (dir & MOVE_LEFT)  move.x -= 1;
    if (dir & MOVE_RIGHT) move.x += 1;

    //Normalize vector
    if (move.x != 0 || move.y != 0) 
    {
        float length = sqrtf(move.x * move.x + move.y * move.y);
        move.x /= length;
        move.y /= length;
    }

    float delta = GetFrameTime();

    player->pos.x += move.x * speed * delta;
    player->pos.y += move.y * speed * delta;
}