/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** main file
*/

#include "include/gol.h"
#include <unistd.h>

int run(settings_t *settings)
{
    if (settings->iterations <= 0)
        return (1);
    if (!game_loops(settings)) {
        endwin();
        return (0);
    }
    settings->iterations -= 1;
    clear();
    print_grid(settings->grid);
    refresh();
    usleep(USLEEP_TIME * 1000);
    return (run(settings));
}

int bonus(settings_t *settings)
{
    initscr();
    curs_set(0);
    print_grid(settings->grid);
    return (run(settings));
}

int main(int argc, char **argv)
{
    settings_t settings;

    if (argc != 3)
        return (84);
    if (!check_args(&settings, argv))
        return (84);
    if (!init_module(&settings))
        return (84);
    if (!bonus(&settings)) {
        destroy_module(&settings);
        return (84);
    }
    endwin();
    destroy_module(&settings);
    return (0);
}
