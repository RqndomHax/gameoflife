/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** game of life header
*/

#ifndef __GOL_H__
#define __GOL_H__

// Wait time before passing to another iteration (in milliseconds)
#define USLEEP_TIME 125

#include <stdlib.h>
#include <ncurses.h>

typedef struct info_s
{
    int target_y;
    int target_x;
    int cells;
    int x;
    int y;
    int phase;
    char **target;
}info_t;

typedef struct word_array_s
{
    char *str;
    char **result;
}word_array_t;

typedef struct settings_s
{
    char *filepath;
    char *content;
    char **grid;
    char **tmp;
    int iterations;
}settings_t;

int init_module(settings_t *);

void destroy_module(settings_t *);

char **my_str_to_word_array(char *);

int my_isnum(char const *);

int my_putstr(char *);

int my_wordcpy(char **, char **);

char **my_worddup(char **);

int read_file(settings_t *);

int check_args(settings_t *, char **);

void free_array(char **);

int game_loops(settings_t *);

void iterate_cells(char **, info_t *);

void print_grid(char **);

#endif