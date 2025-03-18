/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Return if the frist str are over, same,
** or under the size od the second string
*/

#include "my.h"

int end(int comp)
{
    if (comp < 0) {
        return -1;
    }
    return 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int comp = 0;

    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            comp = (s1[i] - s2[i]);
            return (end(comp));
        }
    }
    return 0;
}
