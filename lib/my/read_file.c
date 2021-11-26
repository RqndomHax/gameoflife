/*
** EPITECH PROJECT, 2021
** game of life
** File description:
** returns the content of a file
*/

#include "../../include/gol.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int read_file(settings_t *settings)
{
    int fd = -1;
    struct stat sb;

    fd = open(settings->filepath, O_RDONLY);
    if (fd < 0)
        return (0);
    if (stat(settings->filepath, &sb))
        return (0);
    if (!S_ISREG(sb.st_mode))
        return (0);
    settings->content = malloc(sb.st_size + 1);
    if (!settings->content)
        return (0);
    if (read(fd, settings->content, sb.st_size) == -1) {
        free(settings->content);
        return (0);
    }
    settings->content[sb.st_size] = 0;
    close(fd);
    return (1);
}
