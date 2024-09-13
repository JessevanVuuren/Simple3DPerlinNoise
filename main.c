#include "perlinNoise.h"
#include <raylib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

float size = 10;

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple perlin noise in C");

    SetTargetFPS(60);
    srand(time(NULL));

    int *permutation_table = make_permutation();

    Image img = GenImageColor(SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    Color *pixels = LoadImageColors(img);
    Texture2D texture = LoadTextureFromImage(img);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                float time = GetTime() * 0.5;

                float value = Noise3D(x / (double)SCREEN_HEIGHT * size, y / (double)SCREEN_WIDTH * size, time, permutation_table);
                int color = (int)floor(((value + 1) * 127.5));

                pixels[y * SCREEN_WIDTH + x] = (Color){color, color, color, 255};
            }
        }

        UpdateTexture(texture, pixels);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}