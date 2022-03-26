/*
** EPITECH PROJECT, 2021
** PSU-my_socoban
** File description:
** run_game.c
*/

#include "my.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

void display_game_status(map_infos *map)
{
    int row = 0;

    for (unsigned int i = 0; i < map->length; i++) {
        mvprintw(row++, 0, "%s", map->content[i]);
        refresh();
    }
}

void manage_terminal_display(map_infos *map)
{
    if (LINES >= (int)map->length)
        display_game_status(map);
    else
        mvprintw(LINES / 2, COLS / 2 - 15, "Please, resize the terminal\n");
}

int init_screen(map_infos *map, player_position *pos, char *map_buffer)
{
    int key;
    int gameplay_status = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (gameplay_status != WIN && gameplay_status != LOSE) {
        manage_terminal_display(map);
        refresh();
        key = getch();
        manage_player_movement(map, pos, key);
        manage_filling_boxes(map);
        reset_input(map, pos, key, map_buffer);
        gameplay_status = check_game_status(map);
        clear();
    }
    endwin();
    if (gameplay_status == LOSE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
