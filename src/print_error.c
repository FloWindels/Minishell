/*
** EPITECH PROJECT, 2025
** print_error
** File description:
** print the possible error
*/

#include "my.h"

int print_error_code_follow(int code)
{
    switch (code) {
        case 136:
            my_printf_error("Floating exception (core dumped)\n");
            return 136;
        case 11:
            my_printf_error("Segmentation fault\n");
            return 139;
        default:
            my_printf_error("Unknown error code: %d\n", code);
            return code;
    }
}

int print_error_code(int code, char **command)
{
    switch (code) {
        case 139:
            my_printf_error("Segmentation fault (core dumped)\n");
            return 139;
        case 256:
            return 1;
        case 21504:
            my_printf_error("%s: Command not found.\n", command[0]);
            return 21504;
        case 512:
            return 512;
        default:
            return print_error_code_follow(code);
    }
}
