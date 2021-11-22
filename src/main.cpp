#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

int main()
{
  const int fpsTarget(60);

  const int windowDimensions{384};

  const int enemyAmmount{3};

  InitWindow(windowDimensions, windowDimensions, "Blizzie's Classy Clash");

  Texture2D map = LoadTexture("Maps/Final/Overworld.png");
  const float mapScale{6.0f};
  Vector2 mapPos{0.0, 0.0};
  character pally{windowDimensions, windowDimensions};

  //enemy hound{Vector2{0.f, 0.f}, LoadTexture("Textures/hound_sprite_sheet.png")};

  enemy enemies[enemyAmmount]{
      enemy{Vector2{0.f, 0.f}, LoadTexture("Textures/hound_sprite_sheet.png")},

      enemy{Vector2{400.f, 400.f}, LoadTexture("Textures/hound_sprite_sheet.png")},

      enemy{Vector2{800.f, 800.f}, LoadTexture("Textures/hound_sprite_sheet.png")},
  };

  enemy *enemyPtr[enemyAmmount];

  for (int i = 0; i < enemyAmmount; i++)
  {
    enemyPtr[i] = &enemies[i];
    enemyPtr[i]->setTarget(&pally);
  }

  prop props[2]{
      prop{Vector2{600.f, 300.f}, LoadTexture("Textures/Ore.png")},
      prop{Vector2{400.f, 500.f}, LoadTexture("Textures/DwarvenWarren.png")},

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

    if (pally.getCurrentState() == pally.DEAD)
    {
      DrawText("Game Over!", 55.f, 45.f, 40, RED);
      EndDrawing();
      continue;
    }

    else
    {
      std::string playerHealth = "Health: ";
      playerHealth.append(std::to_string(pally.getPlayerHealth()), 0, 5);
      DrawText(playerHealth.c_str(), 55.f, 45.f, 40, RED);
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
      if (CheckCollisionRecs(pally.GetCollisionRec(), prop.GetCollisionRec(pally.getWorldPos())))
      {
        pally.undoMovement();
      }
    }

    for (auto *enemy : enemyPtr)
    {
      enemy->tick(GetFrameTime());
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      for (auto *enemy : enemyPtr)
      {
        if (CheckCollisionRecs(pally.getSwordCollisionRec(), enemy->GetCollisionRec()))
        {
          enemy->setCurrentState(enemy->DEAD);
        }
      }
    }

    EndDrawing();
  }
  UnloadTexture(map);
  CloseWindow();
}

//shift + alt + f for auto formating in windows