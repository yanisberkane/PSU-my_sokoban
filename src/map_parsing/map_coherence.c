/*
** EPITECH PROJECT, 2021
** PSU-my_socoban
** File description:
** map_coherence.c
*/

#include "my.h"
#include "sokoban.h"
#include <stdlib.h>

void check_map_incoherence(int index, int *boxes_ratio)
{
    if (index != 1) {
        my_putstr_err("There must be only one player!\n");
        exit(ERROR);
    }
    if (boxes_ratio[0] != boxes_ratio[1]) {
        my_putstr_err("Boxes/Empty fileds ratio is FALSE\n");
        exit(ERROR);
    }
}

void check_boxes_ratio(char b, int *boxes_ratio)
{
    if (b == 'X')
        boxes_ratio[0]++;
    if (b == 'O')
        boxes_ratio[1]++;
}

int ignore_line_rt(char c)
{
    if (c == '\n')
        return 1;
    return 0;
}
