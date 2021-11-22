#include "enemy.h"

enemy::enemy(Vector2 pos, Texture2D tex)
{
    worldPos = pos;
    texture = tex;
    width = texture.width / maxFrames;
    height = texture.height / maxRows;
    speed = 3.5f;
}

void enemy::tick(float deltaTime)
{
    if (getCurrentState() == DEAD) return;

    //toTarget = worldPos, targetPos
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if (Vector2Length(velocity) < radius) velocity = {};

    basecharacter::tick(deltaTime);

    if ((CheckCollisionRecs(target->GetCollisionRec(), GetCollisionRec())))
    {
        target->takeDamage(damagePerSec * deltaTime);
    }
    
}

Vector2 enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}