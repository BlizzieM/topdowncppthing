#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

class basecharacter
{
public:
    basecharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle GetCollisionRec();

private:
protected:
    float width{};
    float height{};
    Texture2D texture{LoadTexture("Textures/Palladin_Sprite_Sheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1: facing right, -1 facing left
    float rightLeft{1.f};
    //animation variables
    float runningTime{};
    int frame{};
    int maxFrames{4};
    float updateTime{1.f / 12.f};
    float SheetRow{};
    int maxRows{5};
    float speed{4.f};
    //character state
    enum charState
    {
        idle,
        moving
    };
    charState currentState{idle};
    float scale{4.f};
};

#endif