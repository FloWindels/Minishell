/*
** EPITECH PROJECT, 2025
** pipe
** File description:
** execute command with a pipe
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>

int execute_pipe(char **env, char **pre_path, char *full_command)
{
    int pipefd[2] = {0};
    char **command = my_strtok(full_command, " |");
    int nb_command = my_arrlen(command);
    int return_status = 0;

    if (pipe(pipefd) == -1)
        return -1;
    my_print_char_arr(command);
    if (my_strcmp(command[0], "cd") == 0) {
        return_status = execute_cd(command, env, pre_path);
        return return_status;
    }
    return_status = execute_command(command, env);
    return return_status;
    return 0;
}