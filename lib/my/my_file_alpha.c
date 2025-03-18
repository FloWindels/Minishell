/*
** EPITECH PROJECT, 2024
** my_filealpha
** File description:
** sort a array of string by alphabetic
*/

#include <unistd.h>
#include "my.h"

char is_maj(char maj)
{
    if (maj > 'A' && maj < 'Z')
        return (maj + 32);
    return maj;
}

int my_file_alpha(char **name)
{
    char *temp;
    int cmp = 0;
    int j = 0;

    for (int i = 0; name[i + 1] != NULL; i++) {
        cmp = my_strncmp(name[i], name[i + 1], j);
        if (cmp == 0) {
            j++;
            i--;
        }
        if (cmp > 0) {
            temp = name[i];
            name[i] = name[i + 1];
            name[i + 1] = temp;
            j = 0;
            i = -1;
        }
    }
    my_print_char_arr(name);
    return 1;
}
