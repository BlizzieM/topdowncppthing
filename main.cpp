#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

class character
{
  public:
    Vector2 getWorldPos(){return worldPos;}

    
  private:
    Texture2D texture;
    Vector2 screenPos;
    Vector2 worldPos;
    //animation frames
    float runningTime{};
    int frame{};
    const int maxFrames{4};
    const float updateTime{1.f/12.f};
    float spriteSheetRow{};
    // 1: facing right, -1 facing left
    float rightLeft{1.f};

};

int main()
{
const int fpsTarget(60);

const int windowDimensions{383};

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

// 1: facing right, -1 facing left
float rightLeft{1.f};

//animation vriables
float runningTime{};
int frame{};
const int maxFrames{4};
const float updateTime{1.f/12.f};
float pallySheetRow{};

//character state
enum charState{idle, moving};
charState currentState{idle};

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
      currentState = moving; 
      //set mapPos = mapPos - direction
      Vector2Normalize(direction);
      mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
      direction.x < 0 ? rightLeft = -1.f : rightLeft = 1.f;
   }
   else
   {
     currentState = idle;
   }
  //animation settings for character state
  switch(currentState)
  {
    case idle:
    pallySheetRow = 0.f;
    break;
    case moving:
    pallySheetRow = 1.f;
    break;
    default:
    pallySheetRow = 0.f;
  }


   //draw map
   DrawTextureEx(background,mapPos,0.0,mapScale,WHITE);

   //update animation frame
   runningTime += GetFrameTime();
   if (runningTime >= updateTime)
   {
     frame++;
     runningTime = 0.f;
     if (frame > maxFrames) frame = 0;
   }

   //draw player character
   Rectangle pallySource{frame * (float)pally.width/4.f, pallySheetRow * (float) pally.height/5.f, rightLeft * (float)pally.width/4.f, pally.height/5.f};
   Rectangle pallyDest{pallyPos.x, pallyPos.y, 4.0f * (float)pally.width/4.f, 4.f * pally.height/5.f};
   DrawTexturePro(pally, pallySource, pallyDest, Vector2{}, 0.f, WHITE);
 
  
   EndDrawing();


 }
   UnloadTexture(pally);
   UnloadTexture(background);
   CloseWindow(); 


}