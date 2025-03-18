/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display number
*/

#include "my.h"


int my_put_long(unsigned long int nb)
{
    int i = 1;
    int nb_count = 0;

    while ((nb / i) >= 10) {
        i = i * 10;
    }
    while (i > 0) {
        my_putchar(48 + ((nb / i) % 10));
        i /= 10;
        nb_count++;
    }
    return nb_count;
}
