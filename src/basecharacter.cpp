#include "basecharacter.h"

basecharacter::basecharacter()
{
    
}
void basecharacter::tick(float deltaTime)
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

    Rectangle charSource{frame * width, SheetRow * height, rightLeft * width, height};
    Rectangle charDest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, charSource, charDest, Vector2{}, 0.f, WHITE);
}

void basecharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle basecharacter::GetCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale,
    };
}