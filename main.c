#include <math.h>
#include <stdio.h>
#include <raylib.h>

const int screenWidth = 1000;
const int screenHeight = 1000;

int main(void) {
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    Image img = GenImageColor(screenWidth, screenHeight, WHITE);
    Color *pixels = LoadImageColors(img);
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);


        int color = (int)((sinf(GetTime()) + 1) * 127.5);
        
        for (int y = 0; y < screenHeight; y++) {
            for (int x = 0; x < screenWidth; x++) {
                pixels[y * screenWidth + x] = (Color){0, color, 0, 255};                
            }
        }

        UpdateTexture(texture, pixels);
        DrawTexture(texture, 0, 0, WHITE);

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}