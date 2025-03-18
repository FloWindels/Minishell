/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Display number
*/

#include "my.h"

long put_extreme_min(void)
{
    my_putchar(45);
    my_putchar(50);
    my_putchar(49);
    my_putchar(52);
    my_putchar(55);
    my_putchar(52);
    my_putchar(56);
    my_putchar(51);
    my_putchar(51);
    my_putchar(52);
    my_putchar(56);
    return 11;
}

long my_put_nbr(long nb)
{
    int nb_count = 0;
    long i = 1;

    if (nb == -2147483648) {
        put_extreme_min();
        return 0;
    }
    if (nb < 0) {
        my_putchar(45);
        nb *= -1;
    }
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
