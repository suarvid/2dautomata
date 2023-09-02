#include <stdint.h>
#include <stddef.h>
#include <sand.h>
#include <stdlib.h>
#include <stdio.h>

void update_sand_diagonal(world_t cells, uint16_t x, uint16_t y)
{
    if (empty_left_down(cells, x, y) && empty_right_down(cells, x, y))
    {
        int rand_nr = rand() % 2;

        if (rand_nr == 0)
        {
            move_cell(cells, x, y, x - 1, y + 1);
        }
        else
        {
            move_cell(cells, x, y, x + 1, y + 1);
        }
    }
    else if (empty_left_down(cells, x, y))
    {
        move_cell(cells, x, y, x - 1, y + 1);
    }
    else if (empty_right_down(cells, x, y))
    {
        move_cell(cells, x, y, x + 1, y + 1);
    }
}

void update_sand(world_t cells, uint16_t x, uint16_t y)
{
    cell_t selected_sand = cells[y][x];
    uint16_t speed = selected_sand.speed;

    uint16_t upper_limit = y + speed < WORLD_HEIGHT ? y + speed : WORLD_HEIGHT - 1;

    uint16_t new_y = y;
    while (new_y + 1 < upper_limit && cells[new_y + 1][x].type == EMPTY)
    {
        new_y++;
    }
    if (new_y != y)
    {
        move_cell(cells, x, y, x, new_y);
    }
    else
    {
        update_sand_diagonal(cells, x, y);
    }
}