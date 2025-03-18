/*
** EPITECH PROJECT, 2024
** my_getsign
** File description:
** return the sign in a string
*/

int my_getsign(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 43)
            return 43;
        if (str[i] == 42)
            return 42;
        if (str[i] == 45)
            return 45;
        if (str[i] == 47)
            return 47;
        if (str[i] == 37)
            return 37;
        i++;
    }
    return 0;
}
