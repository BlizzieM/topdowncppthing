#include "character.h"

character::character()
{
    width = texture.width/maxFrames;
    height = texture.height/maxRows;
}

void character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * height)};
}

void character::undoMovement()
{
    worldPos = worldPosLastFrame;
}

void character::tick(float deltaTime)
{ 
    worldPosLastFrame = worldPos;
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        currentState = moving;
        //set worldPos = worldPos + direction
        Vector2Normalize(direction);
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0 ? rightLeft = -1.f : rightLeft = 1.f;
    }
    else
    {
        currentState = idle;
    }

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

    //draw player character
    Rectangle charSource{frame * width, SheetRow * height, rightLeft * width, height};
    Rectangle charDest{screenPos.x, screenPos.y, 4.0f * width, 4.f * height};
    DrawTexturePro(texture, charSource, charDest, Vector2{}, 0.f, WHITE);
}