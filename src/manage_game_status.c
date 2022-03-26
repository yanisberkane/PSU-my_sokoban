/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-yanis.berkane
** File description:
** manage_game_status.c
*/

#include "sokoban.h"
#include "my.h"

int check_stucked_boxes(map_infos *map, int x, int y)
{
    if (map->length < 2)
        return 0;
    if (map->content[x][y] == 'X' && map->content[x + 1][y] == '#'
&& map->content[x][y + 1] == '#' && map->def[x][y] != 'O')
        return 1;
    if (map->content[x][y] == 'X' && map->content[x + 1][y] == '#'
&& map->content[x][y - 1] == '#' && map->def[x][y] != 'O')
        return 1;
    if (map->content[x][y] == 'X' && map->content[x - 1][y] == '#'
&& map->content[x][y - 1] == '#' && map->def[x][y] != 'O')
        return 1;
    if (map->content[x][y] == 'X' && map->content[x - 1][y] == '#'
&& map->content[x][y + 1] == '#' && map->def[x][y] != 'O')
        return 1;
    return 0;
}

int check_lose_condition(map_infos *map)
{
    int checker = 0;
    int colind = 0;

    for (unsigned int x = 0; x < map->length; x++) {
        for (int y = 0; y < map->widths[colind]; y++) {
                checker += check_stucked_boxes(map, x, y);
        }
        colind++;
    }
    if (checker == map->total_boxes) {
        display_game_status(map);
        return 1;
    }
    return 0;
}

void check_boxes_pos(int *checker, char o, char x)
{
    if (o == 'O' && x != 'X')
        *checker = 1;
}

int check_win_condition(map_infos *map)
{
    int checker = 0;
    int colind = 0;

    for (unsigned int x = 0; x < map->length; x++) {
        for (int y = 0; y < map->widths[colind]; y++) {
            check_boxes_pos(&checker, map->def[x][y], map->content[x][y]);
        }
        colind++;
    }
    if (checker == 1)
        return 0;
    display_game_status(map);
    return 1;
}

int check_game_status(map_infos *map)
{
    if (check_win_condition(map) == 1)
        return WIN;
    if (check_lose_condition(map) == 1)
        return LOSE;
    return 0;
}
