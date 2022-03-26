/*
** EPITECH PROJECT, 2021
** My Libraries
** File description:
** my_strisalpha
*/

#include <unistd.h>

int check_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 2;
    return 0;
}

int my_strisalpha(char const *str)
{
    if (str == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_alpha(str[i]) == 0)
            return 0;
    }
    return 1;
}
