/*
** EPITECH PROJECT, 2025
** strdup
** File description:
** duplicate the string
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
    char *dup = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (i = 0; src[i]; i++) {
        dup[i] = src[i];
    }
    dup[i] = '\0';
    return dup;
}
