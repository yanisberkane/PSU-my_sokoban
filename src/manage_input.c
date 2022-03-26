/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-yanis.berkane
** File description:
** manage_input.c
*/

#include "my.h"
#include "sokoban.h"
#include <ncurses.h>

void check_player_mvt(map_infos *map, player_position *pos, int l_r, int u_d)
{
    map->content[pos->x + u_d][pos->y + l_r] = 'P';
    pos->y = pos->y + l_r;
    pos->x = pos->x + u_d;
}

void manage_boxes_mv(map_infos *map, player_position *pos, int l_r, int u_d)
{
    if (map->content[pos->x + u_d][pos->y + l_r] == 'X') {
        map->content[pos->x][pos->y] = ' ';
        map->content[pos->x + u_d * 2][pos->y + l_r * 2] = 'X';
    } else {
        map->content[pos->x][pos->y] = ' ';
    }
}

void check_input(map_infos *map, player_position *pos, int l_r, int u_d)
{
    if (map->length < 2 || map->widths[pos->x] < 2)
        return;
    if (map->content[pos->x + u_d][pos->y] == 'X'
        && (pos->x + u_d * 2 == map->length - 1 || pos->x + u_d * 2 == 0))
        return;
    if ((int)pos->y + l_r == map->widths[pos->x] - 1 || pos->y + l_r == 0)
        return;
    if (pos->x + u_d == map->length - 1 || pos->x + u_d == 0)
        return;
    if (map->content[pos->x + u_d][pos->y + l_r] == '#')
        return;
    if (map->content[pos->x + u_d * 2][pos->y + l_r * 2] == '#'
        && map->content[pos->x + u_d][pos->y + l_r] == 'X')
        return;
    if (map->content[pos->x + u_d * 2][pos->y + l_r * 2] == 'X'
        && map->content[pos->x + u_d][pos->y + l_r] == 'X')
        return;
    manage_boxes_mv(map, pos, l_r, u_d);
    check_player_mvt(map, pos, l_r, u_d);
}

void reset_input(map_infos *map, player_position *pos, int key, char *buff)
{
    if (key == ' ') {
        read_map_content(buff, map);
        get_player_position(*map, pos);
    }
}

void manage_player_movement(map_infos *map, player_position *pos, int key)
{
    if (key == KEY_LEFT)
        check_input(map, pos, LEFT, 0);
    if (key == KEY_RIGHT)
        check_input(map, pos, RIGHT, 0);
    if (key == KEY_UP)
        check_input(map, pos, 0, UP);
    if (key == KEY_DOWN)
        check_input(map, pos, 0, DOWN);
}
