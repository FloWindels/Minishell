/*
** EPITECH PROJECT, 2024
** my put nbr sc
** File description:
** print your number in the scientific version
*/

#include "my.h"

int nota_sc_e(int dot)
{
    int nbcara = 0;

    my_putchar('E');
    if (dot == 0) {
        my_putstr("+00");
        nbcara = nbcara + 2;
        return nbcara;
    }
    nbcara = nbcara + nota_sc_cont(dot, nbcara);
    return nbcara;
}

int my_putnbr_e(double n, long pre)
{
    long div = 1;
    int dot = 0;
    double posn = posi(n);
    double temp = posn;

    if (temp > 9) {
        while (temp > 9) {
            temp = posn / div;
            div = div * 10;
            dot++;
        }
    } else {
        while (temp < 1) {
            temp = posn * div;
            div = div * 10;
            dot--;
        }
    }
    return (my_put_float(temp, pre) + nota_sc_e(dot));
}
