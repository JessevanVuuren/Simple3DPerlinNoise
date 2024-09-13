#include "perlinNoise.h"
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <time.h>

const int screenWidth = 1000;
const int screenHeight = 1000;

float size = 10;

int main(void) {
    InitWindow(screenWidth, screenHeight, "Simple perlin noise in C");

    SetTargetFPS(60);
    // srand(time(NULL));

    int *per = make_permutation();

    Image img = GenImageColor(screenWidth, screenHeight, WHITE);
    Color *pixels = LoadImageColors(img);
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int y = 0; y < screenHeight; y++) {
            for (int x = 0; x < screenWidth; x++) {
                float value = Noise2D(x / (float)screenHeight * size, y / (float)screenWidth * size, per);
                int color = (int)floor(((value + 1) * 127.5));

                pixels[y * screenWidth + x] = (Color){color, color, color, 255};
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