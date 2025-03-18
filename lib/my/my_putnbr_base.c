/*
** EPITECH PROJECT, 2024
** my_putnbr_base
** File description:
** Convert a decimal number into an another base given
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"


long int funct_isneg(long int nbr)
{
    if (nbr < 0) {
        return 4294967296 + nbr;
    }
}

int zero_case(int nbr)
{
    if (nbr == 0) {
        my_put_nbr(0);
        return 0;
    }
}

int my_putnbr_base(long int nbr, char const *base)
{
    long int rest = 0;
    char *result = malloc(1 * sizeof(char));
    int i = 0;

    zero_case(nbr);
    nbr = funct_isneg(nbr);
    while (nbr != 0) {
        rest = nbr % my_strlen(base);
        nbr = nbr / my_strlen(base);
        result[i] += base[rest];
        i++;
    }
    result[i] = '\0';
    my_revstr(result);
    my_putstr(result);
    return my_strlen(result);
}
