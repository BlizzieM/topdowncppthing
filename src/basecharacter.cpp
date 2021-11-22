#include "basecharacter.h"

basecharacter::basecharacter()
{
}
void basecharacter::tick(float deltaTime)
{
    
    worldPosLastFrame = worldPos;

    switch (currentState)
    {
    case IDLE:
        SheetRow = 0.f;
        break;
    case MOVING:
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

        if (Vector2Length(velocity) != 0.0)
    {
        currentState = MOVING;
        //set worldPos = worldPos + direction
        Vector2Normalize(velocity);
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0 ? rightLeft = -1.f : rightLeft = 1.f;
    }
    else
    {
        currentState = IDLE;
    }

    velocity = {};

    //draw character

    Rectangle charSource{frame * width, SheetRow * height, rightLeft * width, height};
    Rectangle charDest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, charSource, charDest, Vector2{}, 0.f, WHITE);
}

void basecharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle basecharacter::GetCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale,
    };
}