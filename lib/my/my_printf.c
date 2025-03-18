/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** a easy version of printf
*/

#include <stdarg.h>
#include "my.h"

int witch_f_follow2(char fonction, va_list ap, int nb_chara)
{
    switch (fonction) {
    case 'u':
        return my_put_unsigned(va_arg(ap, int));
    case 'n':
        *va_arg(ap, int *) = nb_chara;
        return 0;
    case 'p':
        my_putstr("0x");
        return my_putnbr_base((long int)va_arg(ap, long int),
        "0123456789abcdef") + 2;
    case 'e':
        return my_putnbr_sc(va_arg(ap, double), 1000000);
    case 'E':
        return my_putnbr_e(va_arg(ap, double), 1000000);
    default:
        return 0;
    }
}

int witch_f_follow(char fonction, va_list ap, int nb_chara)
{
    switch (fonction) {
    case 'd':
        return my_put_nbr(va_arg(ap, int));
    case 'i':
        return my_put_nbr(va_arg(ap, int));
    case 'f':
        return my_put_float(va_arg(ap, double), 1000000);
    case 'x':
        return my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    case 'X':
        return my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
    case 'o':
        return my_putnbr_base(va_arg(ap, int), "01234567");
    case 'u':
        return my_put_unsigned(va_arg(ap, int));
    default:
        return witch_f_follow2(fonction, ap, nb_chara);
    }
}

int witch_f(char fonction, va_list ap, int nb_chara)
{
    char *str;

    switch (fonction) {
    case 'c':
        my_putchar(va_arg(ap, int));
        return 1;
    case 's':
        str = va_arg(ap, char *);
        my_putstr(str);
        return (my_strlen(str));
    case '%':
        my_putchar('%');
        return 1;
    default:
        return witch_f_follow(fonction, ap, nb_chara);
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int nbcara = 0;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            my_putchar(format[i]);
            nbcara++;
        } else {
            nbcara += witch_f(format[i + 1], ap, nbcara);
            i++;
        }
        i++;
    }
    va_end(ap);
    return nbcara;
}
