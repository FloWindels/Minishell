/*
** EPITECH PROJECT, 2024
** my_put_unsigned
** File description:
** Display unsigned number
*/
#include <limits.h>
#include "my.h"

int my_put_unsigned(long int nb)
{
    if (nb >= 0) {
        return my_put_nbr(nb);
    } else if (nb < 0) {
        return my_put_long(4294967296 + nb);
    }
    return 0;
}
