#include "enemy.h"

enemy::enemy(Vector2 pos, Texture2D tex)
{
    worldPos = pos;
    texture = tex;
    width = texture.width / maxFrames;
    height = texture.height / maxRows;
}

void enemy::tick(float deltaTime)
{
   screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    basecharacter::tick(deltaTime);
}
