/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Copy a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    while (src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    return dest;
}
