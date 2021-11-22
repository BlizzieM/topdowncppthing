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
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    enum charState
    {
        IDLE,
        MOVING,
        DEAD
    };
    charState getCurrentState() { return currentState; }
    void setCurrentState(charState newState) {currentState = newState;}

private:
protected:
    float width{};
    float height{};
    Texture2D texture{LoadTexture("Textures/Palladin_Sprite_Sheet.png")};
    Texture2D sword{LoadTexture("Textures/sword.png")};
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
    charState currentState{IDLE};
    float scale{4.f};
    Vector2 velocity;
};

#endif