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
    empty_cell(world, from_x, from_y);
}

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
move_res_t move_left(world_t world, uint16_t distance)
{
    return MOVE_FAILED;
}
move_res_t move_right(world_t world, uint16_t distance)
{

    return MOVE_FAILED;
}
move_res_t move_up(world_t world, uint16_t distance)
{

    return MOVE_FAILED;
}
move_res_t move_down(world_t world, uint16_t distance)
{
    return MOVE_FAILED;
}
move_res_t move_down_left(world_t world, uint16_t distance)
{
    return MOVE_FAILED;
}
move_res_t move_down_right(world_t world, uint16_t distance)
{
    return MOVE_FAILED;
}

bool within_world_bounds(int16_t x, int16_t y)
{
    return ((x >= 0) && (x < WORLD_WIDTH) && (y >= 0) && (y < WORLD_HEIGHT));
}