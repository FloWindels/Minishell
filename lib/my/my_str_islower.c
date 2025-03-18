/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** Return if string contains only low char
*/

#include "my.h"

int my_str_islower(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    }
    for (int count = 0; count <= my_strlen(str); count++) {
        if (str[count] < 'a' || str[count] > 'z'){
            return 0;
        } else {
            return 1;
        }
    }
}
