/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** manager
*/

#include "../../include/gol.h"

static void run_loop(char **grid, char **tmp, int phase)
{
    info_t infos;

    infos.target = tmp;
    infos.phase = phase;
    for (int y = 0; grid[y]; y++)
        for (int x = 0; grid[y][x]; x++) {
            infos.target_y = y;
            infos.target_x = x;
            iterate_cells(grid, &infos);
        }
}

int game_loops(settings_t *settings)
{
    int initalized = 0;

    if (settings->tmp == NULL) {
        settings->tmp = my_worddup(settings->grid);
        if (!settings->tmp)
            return (0);
        initalized = 1;
    }
    if (!initalized)
        my_wordcpy(settings->grid, settings->tmp);
    for (int phase = 0; phase < 3; phase++)
        run_loop(settings->grid, settings->tmp, phase);
    my_wordcpy(settings->tmp, settings->grid);
    return (1);
}
