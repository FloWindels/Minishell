/*
** EPITECH PROJECT, 2025
** handle_redirection
** File description:
** handle the various redirection
*/

#include "my.h"
#include "mysh.h"

int witch_redirection(char **env, char **pre_path,
    char *command, char *full_command)
{
    int fd = 0;

    if (!my_strcmp(command, "<"))
        my_printf("simple <\n");
    if (!my_strcmp(command, ">"))
        return simple_redirection(env, pre_path, full_command, 0);
    if (!my_strcmp(command, "<<"))
        my_printf("double <<\n");
    if (!my_strcmp(command, ">>"))
        return simple_redirection(env, pre_path, full_command, 1);
}

int handle_redirection(char **env, char **pre_path, char *full_command)
{
    char **redirection = my_strtok(full_command, " ");

    if (!redirection)
        return 84;
    for (int i = 0; redirection[i]; i++) {
        if (redirection[i][0] == '<' || redirection[i][0] == '>')
            witch_redirection(env, pre_path, redirection[i], full_command);
    }
    free_array(redirection);
    return 84;
}
