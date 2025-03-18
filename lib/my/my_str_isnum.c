/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** Return if string contains only num char
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    }
    for (int count = 0; count <= my_strlen(str); count++) {
        if (str[count] < '0' || str[count] > '9'){
            return 0;
        } else {
            return 1;
        }
    }
}
