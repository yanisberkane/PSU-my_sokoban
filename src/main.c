/*
** EPITECH PROJECT, 2021
** PSU-my_sokoban
** File description:
** main.c
*/

#include "my.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

void check_player_sqr(char p, player_position *pos, int x, int y)
{
    if (p == 'P') {
        pos->x = x;
        pos->y = y;
    }
}

void get_player_position(map_infos map, player_position *pos)
{
    int colind = 0;

    for (unsigned int i = 0; i < map.length; i++) {
        for (int j = 0; j < map.widths[colind]; j++) {
            check_player_sqr(map.content[i][j], pos, i, j);
        }
        colind++;
    }
}

void make_free(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int main(int argc, char *const *argv)
{
    map_infos map;
    player_position pos;
    int status = 0;

    if (argc != 2) {
        my_putstr_err("Try '-h' option for help\n");
        exit(ERROR);
    }
    if (my_strcmp("-h", argv[1]) == 0) {
        my_putstr(HELP_MSG);
        exit(EXIT_USAGE);
    }
    read_map_content(argv[1], &map);
    get_player_position(map, &pos);
    status = init_screen(&map, &pos, argv[1]);
    make_free(map.content);
    make_free(map.def);
    free(map.widths);
    return status;
}
