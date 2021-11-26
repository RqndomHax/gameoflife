/*
** EPITECH PROJECT, 2021
** free_array
** File description:
** frees array
*/

#include <stdlib.h>

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; free(array[i]), i++);
    free(array);
}
