#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"

int main()
{
  const int fpsTarget(60);

  const int windowDimensions{384};

  InitWindow(windowDimensions, windowDimensions, "Blizzie's Classy Clash");

  Texture2D map = LoadTexture("Maps/Final/Overworld.png");
  const float mapScale{6.0f};
  Vector2 mapPos{0.0, 0.0};
  Vector2 rockPos{500.f, 400.f};
  character pally{windowDimensions, windowDimensions};
  prop rock{rockPos,LoadTexture("Textures/Ore.png")};

  SetTargetFPS(fpsTarget);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(pally.getWorldPos(), -1.f);

    //draw map
    DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
    rock.Render(pally.getWorldPos());
    pally.tick(GetFrameTime());

    //check map bounds
    if (pally.getWorldPos().x < 0.f ||
        pally.getWorldPos().y < 0.f ||
        pally.getWorldPos().x + windowDimensions > map.width * mapScale ||
        pally.getWorldPos().y + windowDimensions > map.height * mapScale)
    {
      pally.undoMovement();
    }

    EndDrawing();
  }
  UnloadTexture(map);
  CloseWindow();
}