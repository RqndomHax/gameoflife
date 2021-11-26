/*
** EPITECH PROJECT, 2021
** my_wordcpy
** File description:
** It copies string into a target string
*/

int my_wordcpy(char **src, char **target)
{
    int count = 0;
    int x = 0;

    if (!src || !target)
        return (-1);
    for (int i = 0; src[i]; i++) {
        if (!target[i])
            return (count);
        for (x = 0; src[i][x]; count++, x++)
            target[i][x] = src[i][x];
        target[i][x] = 0;
    }
    return (count);
}