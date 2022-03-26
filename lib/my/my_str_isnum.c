/*
** EPITECH PROJECT, 2021
** is_number
** File description:
** returns 0 if all of str is a digit, 1 if it's not
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_str_isnum(char *nb)
{
    if (nb == NULL)
        return 1;
    for (int i = 0; i < my_strlen(nb); i++) {
        if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '-' && nb[i] != '.') {
            return 1;
        }
    }
    return 0;
}
