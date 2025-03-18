/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Return if string a string is printable
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    char *final = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1));
    int count = 0;

    if (!final)
        return NULL;
    for (int i = 0; dest[i]; i++)
        final[i] = dest[i];
    for (count = 0; src[count] != '\0'; count++)
        final[dest_len + count] = src[count];
    final[dest_len + count] = '\0';
    return final;
}
