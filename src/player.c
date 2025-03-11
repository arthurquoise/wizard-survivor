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
    Vector2 target = GetMousePosition();
    float delta = player->speed * GetFrameTime();

    player->pos.x += (target.x - player->pos.x) * delta;
    player->pos.y += (target.y - player->pos.y) * delta;
}