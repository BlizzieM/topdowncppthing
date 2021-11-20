#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"

int main()
{
  const int fpsTarget(60);

  const int windowDimensions{384};

  InitWindow(windowDimensions, windowDimensions, "Blizzie's Classy Clash");

  Texture2D map = LoadTexture("Maps/Final/Overworld.png");
  const float mapScale{6.0f};
  Vector2 mapPos{0.0, 0.0};
  character pally{windowDimensions, windowDimensions};

  enemy hound{Vector2{0.f, 0.f}, LoadTexture("Textures/hound_sprite_sheet.png")};

  hound.setTarget(&pally);
  
  prop props[2]{
    prop{Vector2{600.f, 300.f},LoadTexture("Textures/Ore.png")},
    prop{Vector2{400.f, 500.f},LoadTexture("Textures/DwarvenWarren.png")},

  };

  SetTargetFPS(fpsTarget);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);

    mapPos = Vector2Scale(pally.getWorldPos(), -1.f);

    //draw map
    DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
    
    //draw the props
    for (auto prop : props)
    {
      prop.Render(pally.getWorldPos());
    }
    pally.tick(GetFrameTime());

    //check map bounds
    if (pally.getWorldPos().x < 0.f ||
        pally.getWorldPos().y < 0.f ||
        pally.getWorldPos().x + windowDimensions > map.width * mapScale ||
        pally.getWorldPos().y + windowDimensions > map.height * mapScale)
    {
      pally.undoMovement();
    }


    //check prop collisions
    for (auto prop : props)
    {
      if(CheckCollisionRecs(pally.GetCollisionRec(), prop.GetCollisionRec(pally.getWorldPos())))
      {
        pally.undoMovement();
      }
    }

    hound.tick(GetFrameTime());
    

    EndDrawing();
  }
  UnloadTexture(map);
  CloseWindow();
}