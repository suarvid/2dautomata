#pragma once

#include <stdint.h>
#include <raylib.h>
#include <stdbool.h>

#define WORLD_WIDTH 720
#define WORLD_HEIGHT 720
#define EMPTY 0
#define SAND 1
#define WATER 2
#define WOOD 3
#define FIRE 4

// TODO: These might not be necessary
// as it is unclear what specifies that a move failed.
// Maybe as a return type for move_cell, but not the others?
#define MOVE_FAILED 0
#define MOVE_SUCCESS 1

typedef uint8_t move_res_t;

typedef struct cell
{
    // TODO: Maybe first field could be a function pointer to the update
    // function? (Might not have to be first field).
    // Reduces some logic in main.c that way.
    uint16_t type;
    uint16_t speed; 
    uint16_t density;
    Color color;
    bool moved; // This field might only be useful if we use triple pointers for world_t
    // otherwise, we move the cell and check the value of this field for some other cell... (empty?)
} cell_t;


// TODO?: Performance would likely increase if we used triple pointers
// and just re-assinged pointers to cells, rather than changing the actual
// values in cells stored directly in the matrix (like we're doing now).
// However, that would also be more complicated, do only if needed.
typedef cell_t** world_t;

void empty_cell(world_t world, uint16_t x, uint16_t y);
void move_cell(world_t world, uint16_t from_x, uint16_t from_y, uint16_t to_x, uint16_t to_y);
bool empty_below(world_t world, uint16_t x, uint16_t y);
bool empty_above(world_t world, uint16_t x, uint16_t y);
bool empty_left(world_t world, uint16_t x, uint16_t y);
bool empty_right(world_t world, uint16_t x, uint16_t y);
bool empty_left_down(world_t world, uint16_t x, uint16_t y);
bool empty_right_down(world_t world, uint16_t x, uint16_t y);
move_res_t move_left(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y);
move_res_t move_right(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y);
move_res_t move_up(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y);
move_res_t move_down(world_t world, uint16_t distance, cell_t to_move, uint16_t from_x, uint16_t from_y);
bool within_world_bounds(int16_t x, int16_t y);
