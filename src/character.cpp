#include "character.h"

character::character(int winWidth, int winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height / maxRows;
    screenPos = {static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
                 static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)};
}

void character::tick(float deltaTime)
{
    basecharacter::tick(deltaTime);
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

}