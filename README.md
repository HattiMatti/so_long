# so_long
This project is a very small 2D game with textures, sprites, and some other very basic gameplay elements.

To set up and compile the project, run the following commands in order:

1. `make mlx_get`  
   Downloads the MLX42 graphics library.

2. `make mlx_build`  
   Compiles the MLX42 library.

3. `make`  
   Builds the main project using the compiled MLX42 library.

## Running the Game

After building the project, choose a valid map file with a `.ber` extension and provide it as an argument to the program:

```bash
./so_long "maps/map1.ber"