#include "player.h"

void InitPlayer(Player* player)
{
    player->hp = 100;
    player->pos = (Vector2) {0.0f, 0.0f};
    player->speed = 2.0f;
    player->xp = 0;
}

void UpdatePlayer(Player* player)
{
    UpdateMovement(player);
}

void DrawPlayer(Player* player)
{
    DrawRectangle(player->pos.x, player->pos.y, 32, 32, GREEN);
}

static void UpdateMovement(Player* player)
{
    Vector2 target = GetMousePosition();
    float delta = player->speed * GetFrameTime();

    player->pos.x += (target.x - player->pos.x) * delta;
    player->pos.y += (target.y - player->pos.y) * delta;
}