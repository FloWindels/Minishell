/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Search occurence of a str
*/

#include "my.h"

char *loop(char *str, char const *to_find, int verif, int count)
{
    for (int count2 = 0; count2 <= my_strlen(to_find); count2++) {
            if (str[count + count2] == to_find[count2]) {
                verif++;
            }
        if (verif == my_strlen(to_find)) {
            return &str[count];
        }
        }
}

char *my_strstr(char *str, char const *to_find)
{
    int count = 0;
    int verif = 0;

    my_putchar('\n');
    while (count < (my_strlen(str) - my_strlen(to_find))) {
        count++;
        loop(str, to_find, verif, count);
    }
}
