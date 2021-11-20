#include "raylib.h"
#include "basecharacter.h"

class enemy : public basecharacter
{
public:
    enemy(Vector2 pos, Texture2D tex);
    void tick(float deltaTime, Vector2 knightPos);

private:

};