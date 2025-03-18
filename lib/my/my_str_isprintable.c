/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Return if string a string is printable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    }
    for (int count = 0; count <= my_strlen(str); count++) {
        if (str[count] <= 0 || str[count] >= 31 || str[count] == 127){
            return 0;
        } else {
            return 1;
        }
    }
}
