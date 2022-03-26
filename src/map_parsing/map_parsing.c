/*
** EPITECH PROJECT, 2021
** PSU-my_sokoban
** File description:
** map_parsing.c
*/

#include "my.h"
#include "sokoban.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int *count_cols(char *map_buffer, int lines)
{
    int *counter = malloc(sizeof(int) * lines);
    int tmp_counter = 0;
    int index = 0;

    while (index < lines) {
        for (int i = 0; map_buffer[i] != '\0'; i++) {
            check_columns(map_buffer[i], counter, &tmp_counter, &index);
        }
    }
    return counter;
}

static unsigned int count_lines(char *map_buffer)
{
    unsigned int counter = 0;

    for (int i = 0; map_buffer[i] != '\0'; i++) {
        if (map_buffer[i] == '\n')
            counter++;
    }
    return counter;
}

static void fill_in_map(char *map_buffer, map_infos *map)
{
    int index = 0;
    int colind = 0;

    map->length = count_lines(map_buffer);
    map->widths = count_cols(map_buffer, map->length);
    map->content = malloc(sizeof(char *) * (map->length + 1));
    for (unsigned int i = 0; i < map->length; i++) {
        map->content[i] = malloc(sizeof(char) * (map->widths[colind] + 1));
        for (int j = 0; j < map->widths[colind]; j++) {
            map->content[i][j] = map_buffer[index];
            index++;
            index = index + ignore_line_rt(map_buffer[index]);
        }
        map->content[i][map->widths[colind]] = '\0';
        colind++;
    }
    map->content[map->length] = NULL;
}

static int check_map_syntax(char *map)
{
    int index = 0;
    int boxes_ratio[2] = {0, 0};

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            index++;
        if (map[i] == 'X' || map[i] == 'O')
            check_boxes_ratio(map[i], boxes_ratio);
        if (map[i] != ' ' && map[i] != '#' && map[i] != 'O' && map[i] != 'X'
&& map[i] != 'P' && map[i] != '\n') {
            my_putstr_err(FILE_ERROR_MSG);
            exit(ERROR);
        }
    }
    check_map_incoherence(index, boxes_ratio);
    return boxes_ratio[0];
}

void read_map_content(char *file, __attribute__((unused)) map_infos *map)
{
    int fd = open(file, O_RDONLY);
    char *map_buffer;
    struct stat file_stats;

    if (fd == OPEN_ERR || stat(file, &file_stats) == OPEN_ERR) {
        my_putstr_err(OPEN_ERR_MSG);
        exit(ERROR);
    }
    map->size = file_stats.st_size;
    if (map->size == 0)
        exit(ERROR);
    map_buffer = malloc(sizeof(char) * (map->size + 1));
    if (read(fd, map_buffer, map->size) == -1)
        exit(ERROR);
    map_buffer[map->size] = '\0';
    map->total_boxes = check_map_syntax(map_buffer);
    fill_in_map(map_buffer, map);
    map->def = my_str_arraydup(map->content);
    free(map_buffer);
}
