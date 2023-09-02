#pragma once

#include <stdint.h>
#include <raylib.h>
#include <world.h>
#include <stdbool.h>

#define WORLD_WIDTH 720
#define WORLD_HEIGHT 720
#define EMPTY 0
#define SAND 1
#define WATER 2
#define WOOD 3
#define FIRE 4

#define MOVE_FAILED 0
#define MOVE_SUCCESS 1

typedef uint8_t move_res_t;

typedef struct cell
{
    uint16_t type; 
    uint16_t speed; 
    uint16_t density;
    Color color;
} cell_t;


typedef cell_t** world_t;
void empty_cell(world_t world, uint16_t x, uint16_t y);
void move_cell(world_t world, uint16_t from_x, uint16_t from_y, uint16_t to_x, uint16_t to_y);
bool empty_below(world_t world, uint16_t x, uint16_t y);
bool empty_above(world_t world, uint16_t x, uint16_t y);
bool empty_left(world_t world, uint16_t x, uint16_t y);
bool empty_right(world_t world, uint16_t x, uint16_t y);
bool empty_left_down(world_t world, uint16_t x, uint16_t y);
bool empty_right_down(world_t world, uint16_t x, uint16_t y);
move_res_t move_left(world_t world, uint16_t distance);
move_res_t move_right(world_t world, uint16_t distance);
move_res_t move_up(world_t world, uint16_t distance);
move_res_t move_down(world_t world, uint16_t distance);
bool within_world_bounds(int16_t x, int16_t y);
