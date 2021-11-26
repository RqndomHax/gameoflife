/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** prints string into default output
*/

#include <unistd.h>

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        if (write(1, &str[i], 1) != 1)
            return (0);
    return (1);
}
