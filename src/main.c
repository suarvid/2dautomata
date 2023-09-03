#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <world.h>
#include <sand.h>
#include <water.h>
#include <time.h>

// NOTE: World should always be indexed world[y][x],
// or (equally) world[row][col], NOT world[x][y]
world_t init_empty_world()
{
    uint16_t rows = WORLD_HEIGHT;
    uint16_t cols = WORLD_WIDTH;

    world_t world = malloc(rows * (sizeof(cell_t *)));
    if (world == NULL)
    {
        perror("Failed to allocate memory for world!");
        exit(EXIT_FAILURE);
    }

    for (uint16_t row = 0; row < rows; row++)
    {
        world[row] = malloc(cols * sizeof(cell_t));
        if (world[row] == NULL)
        {
            perror("Failed to allocate memory for row within world!");
            exit(EXIT_FAILURE);
        }
    }

    for (uint16_t row = 0; row < rows; row++)
    {
        for (uint16_t col = 0; col < cols; col++)
        {
            world[row][col].color = GRAY;
            world[row][col].density = 0;
            world[row][col].speed = 0;
            world[row][col].type = EMPTY;
        }
    }

    return world;
}

void render_cells(world_t world)
{
    ClearBackground(RAYWHITE);
    for (size_t y = 0; y < WORLD_HEIGHT; y++)
    {
        for (size_t x = 0; x < WORLD_WIDTH; x++)
        {
            Color color = world[y][x].color;
            DrawRectangle(x, y, 1, 1, color);
        }
    }
    DrawText("S A N D G A M E", 250, 50, 20, LIGHTGRAY);
}

void spawn_if_empty(world_t world, uint16_t x, uint16_t y, cell_t to_spawn)
{
    cell_t cell = world[y][x];
    if (cell.type == EMPTY)
    {
        world[y][x].color = to_spawn.color;
        world[y][x].speed = to_spawn.speed;
        world[y][x].density = to_spawn.density;
        world[y][x].type = to_spawn.type;
        world[y][x].moved = false;
        // world[y][x].color = YELLOW;
        // world[y][x].speed = 5;
        // world[y][x].density = 3;
        // world[y][x].type = SAND;
        //  fprintf(stderr, "Spawned Sand!\n");
    }
}

void spawn_cells(world_t world, cell_t to_spawn)
{
    Vector2 mouse_pos = GetMousePosition();
    uint16_t mouse_y = mouse_pos.y;
    uint16_t mouse_x = mouse_pos.x;
    for (int16_t y_delta = -10; y_delta <= 10; y_delta++)
    {
        int16_t spawn_y = mouse_y + y_delta;
        if (spawn_y >= 0 && spawn_y < WORLD_HEIGHT)
        {
            for (int16_t x_delta = -10; x_delta <= 10; x_delta++)
            {
                int16_t spawn_x = mouse_x + x_delta;
                if (spawn_x >= 0 && spawn_x < WORLD_WIDTH)
                {
                    spawn_if_empty(world, spawn_x, spawn_y, to_spawn);
                }
            }
        }
    }
}

// Updates the cell grid, bottom-up, left to right
void update_cells(world_t world)
{
    for (uint16_t y = WORLD_HEIGHT - 1; y > 0; y--)
    {
        for (uint16_t x = 0; x < WORLD_WIDTH; x++)
        {
            cell_t cell = world[y][x];
            switch (cell.type)
            {
            case SAND:
                update_sand(world, x, y);
                break;
            case WATER:
                update_water(world, x, y);
                break;

            default:
                break;
            }
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    const int screen_width = WORLD_WIDTH;
    const int screen_height = WORLD_HEIGHT;

    InitWindow(screen_width, screen_height, "Basic Window");
    SetTargetFPS(60);
    world_t world = init_empty_world();
    cell_t selected_cell_t = SAND_CELL_T;

    while (!WindowShouldClose())
    {
        update_cells(world);
        BeginDrawing();
        {
            render_cells(world);
        }
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            fprintf(stderr, "Left Mouse pressed!\n");
            spawn_cells(world, selected_cell_t);
        }
        // TODO: This is shit, just for testing
        if (IsKeyPressed(KEY_S))
        {
            selected_cell_t = SAND_CELL_T;
        }
        if (IsKeyPressed(KEY_W))
        {
            selected_cell_t = WATER_CELL_T;
        }
    }

    CloseWindow();

    return EXIT_SUCCESS;
}