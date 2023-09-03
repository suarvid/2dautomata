#include <world.h>
#include <stdint.h>
#include <raylib.h>

void empty_cell(world_t world, uint16_t x, uint16_t y)
{
    world[y][x].type = EMPTY;
    world[y][x].color = GRAY;
    world[y][x].speed = 0;
    world[y][x].density = 0;
}

// Writes the fields of the cell at world[from_y][from_x] to the cell at
// world[to_y][to_x], and writes an empty cell at the original position.
void move_cell(world_t world, uint16_t from_x, uint16_t from_y, uint16_t to_x, uint16_t to_y)
{
    cell_t to_move = world[from_y][from_x];
    world[to_y][to_x].color = to_move.color;
    world[to_y][to_x].density = to_move.density;
    world[to_y][to_x].speed = to_move.speed;
    world[to_y][to_x].type = to_move.type;
    world[to_y][to_x].moved = true;
    empty_cell(world, from_x, from_y);

}

// TODO: Need to write functions for comparing the density between cells,
// not just checking if a position is empty, as sand for example will
// sink in water, since sand is more dense than water, but oil should
// float on top of water, since it is less dense than water.
bool empty_below(world_t world, uint16_t x, uint16_t y)
{
    if (within_world_bounds(x, y + 1))
        return world[y + 1][x].type == EMPTY;
    return false;
}

bool empty_above(world_t world, uint16_t x, uint16_t y)
{
    if (within_world_bounds(x, y - 1))
        return world[y - 1][x].type == EMPTY;
    return false;
}

bool empty_left(world_t world, uint16_t x, uint16_t y)
{
    if (within_world_bounds(x - 1, y))
        return world[y][x - 1].type == EMPTY;
    return false;
}

bool empty_right(world_t world, uint16_t x, uint16_t y)
{
    if (within_world_bounds(x + 1, y))
        return world[y][x + 1].type == EMPTY;
    return false;
}

bool empty_left_down(world_t world, uint16_t x, uint16_t y)
{
    return empty_left(world, x, y + 1);
}

bool empty_right_down(world_t world, uint16_t x, uint16_t y)
{
    return empty_right(world, x, y + 1);
}

// TODO: Make use of these instead of doing everything "manually"
// Also maybe break out common functionality into some nice function
// as the operator is basically all that changes
move_res_t move_left(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    int16_t dist_actual = 0;
    while (within_world_bounds(from_x - dist_actual - 1, from_y) &&
           world[from_y][from_x - dist_actual - 1].type == EMPTY)
    {
        dist_actual++;
    }

    move_cell(world, from_x, from_y, from_x - dist_actual, from_y);
    return MOVE_SUCCESS;
}

move_res_t move_right(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    int16_t dist_actual = 0;
    while (within_world_bounds(from_x + dist_actual + 1, from_y) &&
           world[from_y][from_x + dist_actual + 1].type == EMPTY)
    {
        dist_actual++;
    }

    move_cell(world, from_x, from_y, from_x + dist_actual, from_y);
    return MOVE_SUCCESS;
}

move_res_t move_up(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    int16_t dist_actual = 0;
    while (within_world_bounds(from_x, from_y - dist_actual - 1) &&
           world[from_y - dist_actual - 1][from_x].type == EMPTY)
    {
        dist_actual++;
    }

    move_cell(world, from_x, from_y, from_x, from_y - dist_actual);
    return MOVE_SUCCESS;
}

move_res_t move_down(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    int16_t dist_actual = 0;
    while (within_world_bounds(from_x, from_y + dist_actual + 1) &&
           world[from_y + dist_actual + 1][from_x].type == EMPTY)
    {
        dist_actual++;
    }

    move_cell(world, from_x, from_y, from_x, from_y + dist_actual);
    return MOVE_SUCCESS;
}

// TODO: Implement below
move_res_t move_down_left(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    return MOVE_FAILED;
}

move_res_t move_down_right(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    return MOVE_FAILED;
}

move_res_t move_up_left(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    return MOVE_FAILED;
}

move_res_t move_up_right(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y)
{
    return MOVE_FAILED;
}

bool within_world_bounds(int16_t x, int16_t y)
{
    return ((x >= 0) && (x < WORLD_WIDTH) && (y >= 0) && (y < WORLD_HEIGHT));
}