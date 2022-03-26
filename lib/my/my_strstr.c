/*
** EPITECH PROJECT, 2021
** My Libraries
** File description:
** my_strstr
*/

#include <unistd.h>

int check_similar(char *str, int i, char const *to_find)
{
    int ind = 0;

    for (int j = 0; to_find[j] != '\0'; j++) {
        if (to_find[j] == str[i])
            ind = 1;
        else
            return 0;
        i++;
    }
    return ind;
}

char *my_strstr(char *str, char const *to_find)
{
    char *pos_str = NULL;

    if (str == NULL || to_find == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0] && check_similar(str, i, to_find)) {
            pos_str = str + i;
            return pos_str;
        } else
            continue;
    }
    return NULL;
}
