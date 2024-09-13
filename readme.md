# Perlin Noise Map Display using Raylib
## Overview
This C project demonstrates the generation and visualization of a 2D noise map using the Perlin noise algorithm. The noise map is rendered on a window using Raylib, where each point in the grid is assigned a grayscale value corresponding to the Perlin noise value for its (x, y) coordinates.


---

Most of the code used to implement the Perlin noise function is adapted from the [Perlin Noise Algorithm Guide by Rachid Touti](https://rtouti.github.io/graphics/perlin-noise-algorithm).

### Features
- Generates a 2D Perlin noise map.
- Renders the noise map as a grayscale image where black represents the minimum noise value and white represents the maximum.
- Uses Raylib for the graphical rendering.


## build
build is currently for windows only

`$ make`

## run the project

`$ out.exe`