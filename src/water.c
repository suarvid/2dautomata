#include <stdint.h>
#include <stddef.h>
#include <water.h>
#include <sand.h>
#include <stdlib.h>
#include <stdio.h>

void update_water(world_t world, uint16_t x, uint16_t y)
{
    if (!update_sand(world, x, y))
    {
        if (empty_left(world, x, y))
        {
            move_left(world, world[y][x].speed, world[y][x], x, y);
        }
        else if (empty_right(world, x, y))
        {
            move_right(world, world[y][x].speed, world[y][x], x, y);
        }
    }
}