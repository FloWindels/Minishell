/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int count = 0;
    int rev_count = my_strlen(str);
    char rev[my_strlen(str)+1];

    for (int rev_count = my_strlen(str) - 1; rev_count >= 0; rev_count--) {
        rev[count] = str[rev_count];
        count++;
    }
    for (int i = 0; i < my_strlen(str); i++) {
        str[i] = rev[i];
    }
    return str;
}
