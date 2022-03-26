/*
** EPITECH PROJECT, 2021
** sokoban_h
** File description:
** Library header
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H

    typedef struct m_infos {
        char **content;
        unsigned int size;
        unsigned int length;
        int *widths;
        int total_boxes;
        char **def;
    } map_infos;

    typedef struct p_pos {
        unsigned int x;
        unsigned int y;
    } player_position;

    #define ERROR 84
    #define ERROR_MSG "error\n"
    #define OPEN_ERR_MSG "No such file.\n"
    #define FILE_ERROR_MSG "file format error\n"
    #define EXIT_USAGE 0
    #define OPEN_ERR -1
    #define HELP_MSG "USAGE\n\
    ./my_sokoban map\n\
DESCRIPTION\n\
    map file representing the warehouse map, containing '#' for walls,\n\
        'P' for the player, 'X' for boxes and 'O' for storage locations.\n"
    #define UP -1
    #define DOWN 1
    #define LEFT -1
    #define RIGHT 1
    #define WIN 1
    #define LOSE 2

void read_map_content(char *file, __attribute__((unused)) map_infos *map);
void get_player_position(map_infos map, player_position *pos);
int init_screen(map_infos *map, player_position *pos, char *map_buffer);
int ignore_line_rt(char c);
void check_boxes_ratio(char b, int *boxes_ratio);
void check_map_incoherence(int index, int *boxes_ratio);
void check_input(map_infos *map, player_position *pos, int l_r, int u_d);
void reset_input(map_infos *map, player_position *pos, int key, char *buff);
void check_player_mvt(map_infos *map, player_position *pos, int l_r, int u_d);
void manage_player_movement(map_infos *map, player_position *pos, int key);
void manage_filling_boxes(map_infos *map);
int check_game_status(map_infos *map);
void display_game_status(map_infos *map);
void check_columns(char c, int *counter, int *tmp_counter, int *index);

#endif
