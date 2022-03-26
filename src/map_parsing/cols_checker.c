/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-yanis.berkane
** File description:
** cols_checker.c
*/

#include "my.h"
#include "sokoban.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void check_columns(char c, int *counter, int *tmp_counter, int *index)
{
    if (c == '\n') {
        counter[*index] = *tmp_counter;
        *tmp_counter = 0;
        *index = *index + 1;
    } else {
        *tmp_counter = *tmp_counter + 1;
    }
}
