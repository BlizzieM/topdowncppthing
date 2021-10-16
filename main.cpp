#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

int main()
{
const int fpsTarget(60);

const int windowDimensions{384};

InitWindow(windowDimensions, windowDimensions, "Blizzie's Classy Clash");


Texture2D background = LoadTexture("Maps/Final/Overworld.png");
const float mapScale{6.0f};
Vector2 mapPos{0.0, 0.0};


float speed{4.0f};

Texture2D pally = LoadTexture("Textures/Palladin_Sprite_Sheet.png");
Vector2 pallyPos{
  (float)windowDimensions/2.0f - 4.0f * (0.5f * (float)pally.width/4.0f),
  (float)windowDimensions/2.0f - 4.0f * (0.5f * (float)pally.height/5.0f)
};

SetTargetFPS(fpsTarget);
 while(!WindowShouldClose())
 {
   BeginDrawing();
   ClearBackground(WHITE);

   //Draw Background
   Vector2 direction{};
   if (IsKeyDown(KEY_A)) direction.x -= 1.0;
   if (IsKeyDown(KEY_D)) direction.x += 1.0;
   if (IsKeyDown(KEY_W)) direction.y -= 1.0;
   if (IsKeyDown(KEY_S)) direction.y += 1.0;
   if (Vector2Length(direction) != 0.0)
   {
      //set mapPos = mapPos - direction
      Vector2Normalize(direction);
      mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
   }
   //draw map
   DrawTextureEx(background,mapPos,0.0,mapScale,WHITE);

   //draw player character
   Rectangle pallySource{0.f, 0.f, (float)pally.width/4.f, pally.height/5.f};
   Rectangle pallyDest{pallyPos.x, pallyPos.y, 4.0f * (float)pally.width/4.f, 4.f * pally.height/5.f};
   DrawTexturePro(pally, pallySource, pallyDest, Vector2{}, 0.f, WHITE);
 
  
   EndDrawing();


 }
   UnloadTexture(pally);
   UnloadTexture(background);
   CloseWindow(); 


}