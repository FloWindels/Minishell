/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** same than my_strcmp but with bytes
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int comp = 0;

    for (int i = 0; i <= n; i++) {
        if (s1[i] != s2[i]) {
            comp = (s1[i] - s2[i]);
            return (comp);
        }
    }
    return 0;
}
