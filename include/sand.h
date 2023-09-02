#pragma once

#include <stdint.h>
#include <world.h>

void update_sand(world_t cells, uint16_t x, uint16_t y);
void update_sand_diagonal(world_t cells, uint16_t x, uint16_t y);