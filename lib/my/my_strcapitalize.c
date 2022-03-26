/*
** EPITECH PROJECT, 2021
** My Libraries
** File description:
** my_strcapitalize
*/

#include <unistd.h>
#include "my.h"

int check_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return LOWER_CASE;
    if (c >= 'A' && c <= 'Z')
        return UPPER_CASE;
    if (c == ' ' || c == '\t' || c == '+' || c == '-')
        return SEP;
    return 0;
}

void convert_string(char *str, int i)
{
    if (check_char(str[i]) == LOWER_CASE && check_char(str[i - 1]) == SEP)
        str[i] -= CONVERT;
    if (check_char(str[i]) == UPPER_CASE && check_char(str[i - 1]) != SEP)
        str[i] += CONVERT;
}

char *my_strcapitalize(char *str)
{
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && check_char(str[i]) == LOWER_CASE)
            str[i] -= CONVERT;
        else
            convert_string(str, i);
    }
    return str;
}
