/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** module manager
*/

#include "../../include/gol.h"

void destroy_module(settings_t *settings)
{
    if (settings->content)
        free(settings->content);
    if (settings->grid)
        free_array(settings->grid);
    if (settings->tmp)
        free_array(settings->tmp);
}

int init_module(settings_t *settings)
{
    if (!read_file(settings))
        return (0);
    for (int i = 0; settings->content[i]; i++) {
        if (settings->content[i] == '\n')
            continue;
        if (settings->content[i] == '.' || settings->content[i] == 'X')
            continue;
        free(settings->content);
        return (0);
    }
    settings->grid = my_str_to_word_array(settings->content);
    if (!settings->grid) {
        free(settings->content);
        return (0);
    }
    settings->tmp = NULL;
    return (1);
}
