/*
** EPITECH PROJECT, 2021
** my_worddup
** File description:
** It allocates memory and copies the array given as argument in it
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int size = 0;

    for (; str[size]; size++);
    return (size);
}

static int my_wordlen(char **str)
{
    int size = 0;

    for (; str[size]; size++);
    return (size);
}

char **my_worddup(char **src)
{
    char **dest = NULL;
    int x = 0;
    int wordlen = 0;

    wordlen = my_wordlen(src);
    dest = malloc(sizeof(char *) * (wordlen + 1));
    if (!dest)
        return (NULL);
    for (int n = 0; n <= wordlen; dest[n++] = NULL);
    for (int i = 0; src[i]; i++) {
        dest[i] = malloc(my_strlen(src[i]) + 1);
        if (!dest[i])
            return (dest);
        for (x = 0; src[i][x]; x++)
            dest[i][x] = src[i][x];
        dest[i][x] = 0;
    }
    return (dest);
}
