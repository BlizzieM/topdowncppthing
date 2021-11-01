#include "prop.h"

prop::prop(Vector2 pos, Texture2D tex) : worldPos(pos),
                                         texture(tex)
{
}

void prop::Render(Vector2 knightPos)
{
    screenPos = Vector2Subtract(worldPos, knightPos);

    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}