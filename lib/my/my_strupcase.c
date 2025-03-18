/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** Upper case of string
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int count = 0; count <= my_strlen(str); count++) {
        if (str[count] >= 'a' && str[count] <= 'z' && str[count] != ' ') {
            str[count] = str[count] - 32;
        }
    }
    return str;
}
