/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Copy n letter of a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n, int start)
{
    int count = 0;

    for (; count < n && src[start + count] != '\0'; count++) {
        dest[count] = src[start + count];
    }
    dest[count] = '\0';
    return dest;
}
