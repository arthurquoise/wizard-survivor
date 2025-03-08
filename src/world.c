#include "world.h"

void InitWorld()
{
    floor = LoadTexture("resources/floor.png"); 
}

void DrawWorld()
{
    for (int y = 0; y < 600; y += floor.height)
    {
        for (int x = 0; x < 600; x += floor.width)
        {
                DrawTextureV(floor, (Vector2){x, y}, WHITE);
        }
    }
}