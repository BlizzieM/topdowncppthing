#include "raylib.h"
#include "basecharacter.h"
#include "character.h"

class enemy : public basecharacter
{
public:
    enemy(Vector2 pos, Texture2D tex);
    virtual void tick(float deltaTime) override;
    void setTarget(character *targ) { target = targ; };
    virtual Vector2 getScreenPos() override;

private:
    character *target;
    Vector2 targPos;
    float damagePerSec{10.f};
    float radius{25.f};
};