/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** check if args are valid
*/

#include "../../include/gol.h"

int check_args(settings_t *settings, char **argv)
{
    if (!my_isnum(argv[2]))
        return (0);
    settings->iterations = atoi(argv[2]);
    if (settings->iterations < 0)
        return (0);
    settings->filepath = argv[1];
    settings->content = NULL;
    settings->grid = NULL;
    return (1);
}
