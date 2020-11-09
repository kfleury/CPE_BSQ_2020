//
// Created by kfleury on 04/11/2020.
//

#ifndef BSQ_2020_BSQ_H
#define BSQ_2020_BSQ_H

#include "my.h"

static const int INT_MAX = 2147483647;
static const int ERROR_NUMBER = 84;
static const int EXIT_ERROR = 84;

typedef struct pos_s {
    int nbr;
    int pos;
} pos_t;

int open_the_map(char *, char **, int **);
void find_the_square(char **, int *);

#endif //BSQ_2020_BSQ_H
