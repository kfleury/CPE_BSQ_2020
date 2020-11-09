/*
** EPITECH PROJECT, 2020
** BSQ_2020
** File description:
** bsq.c
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

static int minus_nbr(int nb1, int nb2, int nb3)
{
    int min = nb1;

    if (min > nb2)
        min = nb2;
    if (min > nb3)
        min = nb3;
    return (min);
}

static void put_square(char **buffer, pos_t pos, int length)
{
    for (int j = 0; j != pos.nbr; j++) {
        for (int i = pos.pos; i != (pos.pos - pos.nbr); i--)
            (*buffer)[i] = 'x';
        pos.pos -= length + 1;
    }
}

void find_the_square(char **buffer, int *temp)
{
    pos_t pos = {0, 0};
    int length = 0;

    for (; (*buffer)[length] != '\n'; length++);
    for (int i = 0; (*buffer)[i+1]; i++) {
        if ((*buffer)[i] == '\n') {
            i += 1;
                temp[i] = (*buffer)[i] == '.';
            i += 1;
        }
        temp[i] = (*buffer)[i] == '.';
        if ((*buffer)[i] == '.' && i >= length + 2)
            temp[i] = 1 + minus_nbr(temp[i-1],temp[i-length-1],temp[i-length-2]);
        if (temp[i] > pos.nbr)
            pos = (pos_t) { temp[i], i };
    }
    put_square(buffer, pos, length);
}

int open_the_map(char *path, char **buffer, int **temp)
{
    int fd;
    struct stat data;

    if ((stat(path,&data))==-1 || (*buffer = malloc(data.st_size + 1))==NULL
        || (fd = open(path,O_RDONLY))==-1 || (read(fd, *buffer, data.st_size+1)==-1)
        || (*temp = malloc(sizeof(int) * data.st_size)) == NULL)
        return (84);
    (*buffer)[data.st_size] = '\0';
    for (; **buffer != 'o' && **buffer != '.'; (*buffer)++);
    return (close(fd) == -1 ? 84 : 0);
}