#pragma once

#include <stdint.h>
#include <world.h>
#include <stdbool.h>

bool update_sand(world_t cells, uint16_t x, uint16_t y);

struct cell SAND_CELL_T = {
    .color = YELLOW,
    .density = 5,
    .moved = false,
    .speed = 3,
    .type = SAND
};