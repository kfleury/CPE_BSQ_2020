/*
** EPITECH PROJECT, 2020
** BSQ_2020
** File description:
** main.c
*/
#include <stddef.h>
#include "bsq.h"

/*
 * Valgrind error in the find_the_square function due to unknown reason.
 * If someone ever find wp to you !
 */

int main(int ac, char **av)
{
    int *buff_temp = NULL;
    char *buffer = NULL;

    if (ac != 2 || open_the_map(av[1], &buffer, &buff_temp) == ERROR_NUMBER)
        return (EXIT_ERROR);
    find_the_square(&buffer, buff_temp);
    my_putstr(buffer);
    return (EXIT_SUCCESS);
}