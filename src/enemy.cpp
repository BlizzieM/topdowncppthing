#include "enemy.h"

enemy::enemy(Vector2 pos, Texture2D tex)
{
    worldPos = pos;
    texture = tex;
    width = texture.width / maxFrames;
    height = texture.height / maxRows;
}

void enemy::tick(float deltaTime, Vector2 knightPos)
{
    worldPosLastFrame = worldPos;

    switch (currentState)
    {
    case idle:
        SheetRow = 0.f;
        break;
    case moving:
        SheetRow = 1.f;
        break;
    default:
        SheetRow = 0.f;
    }
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    //draw character

    Vector2 screenPos{(Vector2Subtract(worldPos, knightPos))};
    Rectangle charSource{frame * width, SheetRow * height, rightLeft * width, height};
    Rectangle charDest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, charSource, charDest, Vector2{}, 0.f, WHITE);
}
