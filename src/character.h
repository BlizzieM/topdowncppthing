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


private:

};

#endif