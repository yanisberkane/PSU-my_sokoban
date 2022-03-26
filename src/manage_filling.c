/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-yanis.berkane
** File description:
** manage_filling.c
*/

#include "my.h"
#include "sokoban.h"

void refresh_empty_filling(map_infos *map, unsigned int x, unsigned int y)
{
    if (map->content[x][y] == ' ' && map->def[x][y] == 'O')
        map->content[x][y] = 'O';
}

void manage_filling_boxes(map_infos *map)
{
    int colind = 0;

    for (unsigned int x = 0; x < map->length; x++) {
        for (int y = 0; y < map->widths[colind]; y++) {
            refresh_empty_filling(map, x, y);
        }
        colind++;
    }
}
