/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int check_after_num(const char *str, int i, int number_find)
{
    if (check_number(str, i) == 1) {
        number_find *= 10;
        number_find += str[i] - 48;
        return (check_after_num(str, i + 1, number_find));
    }
    return number_find;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int number_find = 0;
    int minus = 1;

    if (check_lettre(str, 0) == 1) {
        return 0;
    }
    while (str[i] != '\0') {
        if (str[i] == '-') {
            minus *= -1;
        }
        if (check_number(str, i) == 1) {
            number_find = str[i] - 48;
            return ((check_after_num(str, i + 1, number_find)) * minus);
        }
        i++;
    }
}
