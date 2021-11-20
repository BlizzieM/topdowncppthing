#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "basecharacter.h"

class character : public basecharacter
{
public:
    character(int winWidth, int winHeight);
    void tick(float deltaTime);


private:

};