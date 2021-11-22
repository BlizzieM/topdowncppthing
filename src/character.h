#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "basecharacter.h"

class character : public basecharacter
{
public:
    character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getSwordCollisionRec() const {return swordCollisionRec;}
    float getPlayerHealth() const {return health;}
    void takeDamage(float damage);
private:
    int windowWidth{};
    int windowHeight{};
    Rectangle swordCollisionRec{};
    float health{100.f};
};

#endif