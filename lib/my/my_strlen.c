/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Display len of a string
*/
#include <stdio.h>
#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return -1;
    }
    while (str[count] != '\0'){
        count++;
    }
    return (count);
}
