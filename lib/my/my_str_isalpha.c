/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** Return if string contains only alpha char
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int count = 0; count <= my_strlen(str); count++) {
        if ((str[count] < 'a' && str[count] > 'z' && str[count] != ' ') ||
        (str[count] < 'A' && str[count] > 'Z' && str[count] != ' ')) {
            return 0;
    } else {
        return 1;
    }
    }
}
