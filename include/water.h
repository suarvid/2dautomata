#pragma once
#include <world.h>
#include <raylib.h>

void update_water(world_t world, uint16_t x, uint16_t y);

struct cell WATER_CELL_T = {
    .color = BLUE,
    .density = 2,
    .moved = false,
    .speed = 6,
    .type = WATER
};