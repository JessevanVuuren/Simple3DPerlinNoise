#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define PERMUTATION_SIZE 255

typedef struct {
    float x;
    float y;
} Point;


void shuffle(int *arr, int arr_n) {
    for (int i = arr_n - 1; i > 0; i--) {
        int index = round(rand() % i);
        int temp = arr[i];

        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int *make_permutation() {
    int *permutation = (int *)malloc(sizeof(int) * PERMUTATION_SIZE * 2);

    for (size_t i = 0; i < PERMUTATION_SIZE; i++) permutation[i] = i;

    shuffle(permutation, PERMUTATION_SIZE);

    for (size_t i = 0; i < PERMUTATION_SIZE; i++) permutation[PERMUTATION_SIZE + i] = permutation[i];

    return permutation;
}

Point get_constant_vector(int value_of_perm_table) {
    int h = value_of_perm_table & 3;

    if (h == 0)
        return (Point){1.0, 1.0};
    else if (h == 1)
        return (Point){-1.0, 1.0};
    else if (h == 2)
        return (Point){-1.0, -1.0};
    else
        return (Point){1.0, -1.0};
}

float fade_curve(float t) {
    // why this works, joost mag het weten
    return ((6 * t - 15) * t + 10) * t * t * t;
}

float lerp(float t, float a1, float a2) {
    return a1 + t * (a2 - a1);
}

float dot_product(Point p, Point p2) {
    return p.x * p2.x + p.y * p2.y;
}

float Noise2D(float x, float y, int* perm_table) {
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;

    float xf = x - floor(x);
    float yf = y - floor(y);

    Point topRight = (Point){.x = xf - 1.0, .y = yf - 1.0};
    Point topLeft = (Point){.x = xf, .y = yf - 1.0};
    Point bottomRight = (Point){.x = xf - 1.0, .y = yf};
    Point bottomLeft = (Point){.x = xf, .y = yf};

    int valueTopRight = perm_table[perm_table[X + 1] + Y + 1];
    int valueTopLeft = perm_table[perm_table[X] + Y + 1];
    int valueBottomRight = perm_table[perm_table[X + 1] + Y];
    int valueBottomLeft = perm_table[perm_table[X] + Y];

    float dotTopRight = dot_product(topRight, get_constant_vector(valueTopRight));
    float dotTopLeft = dot_product(topLeft, get_constant_vector(valueTopLeft));
    float dotBottomRight = dot_product(bottomRight, get_constant_vector(valueBottomRight));
    float dotBottomLeft = dot_product(bottomLeft, get_constant_vector(valueBottomLeft));

    float u = fade_curve(xf);
    float v = fade_curve(yf);

    return lerp(u, 
        lerp(v, dotBottomLeft, dotTopLeft), 
        lerp(v, dotBottomRight, dotTopRight)
    );
}