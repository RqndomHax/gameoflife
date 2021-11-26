/*
** EPITECH PROJECT, 2021
** my_getline
** File description:
** get shell input
*/

#include <stdio.h>

char *my_getline(void)
{
    char *array = NULL;
    size_t bufsize;

    if (getline(&array, &bufsize, stdin) == -1)
        return (NULL);
    return (array);
}
