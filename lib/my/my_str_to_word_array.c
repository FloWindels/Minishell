/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Function that splits a string into words.
*/

#include "my.h"
#include <stdlib.h>

int separator(char const *str, int i)
{
    if (check_lettre(str, i) == 0 && check_number(str, i) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int compt_separator(char const *str)
{
    int compt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (separator(str, i) == 1
        && (check_lettre(str, i + 1) == 1 || check_number(str, i + 1) == 1)) {
            compt++;
        }
    }
    return (compt + 1);
}

char *word(int z, int mark, const char *str)
{
    char *word;
    int j = 0;

    word = malloc(sizeof(char) * (z - mark));
    for (j = 0; j < (z - mark); j++) {
        word[j] = str[mark + j];
    }
    word[j] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    char **array;
    int length = my_strlen(str) + 1;
    int nbw = compt_separator(str);
    int mark = 0;
    int i = 0;

    array = malloc(sizeof(char *) * (nbw + 1));
    array[nbw] = NULL;
    for (int z = 0; z < length; z++) {
        if (separator(str, z) == 0)
            continue;
        if (z == mark){
            mark = z + 1;
            continue;
        }
        array[i] = word(z, mark, str);
        mark = z + 1;
        i++;
    }
    return (array);
}
