/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** utils
*/

#include "../../include/gol.h"
#include <unistd.h>

static void check_cell(char **grid, info_t *infos)
{
    if (infos->y == infos->target_y)
        if (infos->x == infos->target_x)
            return;
    if (grid[infos->y][infos->x] == 'X')
        infos->cells += 1;
}

void iterate_cells(char **grid, info_t *i)
{
    int mx = i->target_x - 1;
    int my = i->target_y - 1;
    int xmax = i->target_x + 1;
    int ymax = i->target_y + 1;

    i->cells = 0;
    if (my < 0)
        my++;
    if (mx < 0)
        mx++;
    for (i->y = my; i->y <= ymax && grid[i->y]; i->y += 1)
        for (i->x = mx; i->x <= xmax && grid[i->y][i->x]; i->x += 1)
            check_cell(grid, i);
    if (i->cells == 3 && i->phase == 0)
        i->target[i->target_y][i->target_x] = 'X';
    if (i->cells <= 1 && i->phase == 1)
        i->target[i->target_y][i->target_x] = '.';
    if (i->cells >= 4 && i->phase == 2)
        i->target[i->target_y][i->target_x] = '.';
}

void print_grid(char **grid)
{
    for (int y = 0; grid[y]; y++) {
        for (int x = 0; grid[y][x]; x++)
            addch(grid[y][x]);
        addch('\n');
    }
}
