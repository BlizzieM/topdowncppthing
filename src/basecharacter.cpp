#include "basecharacter.h"

basecharacter::basecharacter()
{
    
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