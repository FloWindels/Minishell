/*
** EPITECH PROJECT, 2025
** init_pipe
** File description:
** initialise the use of pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

int init_pipe(char **env, char **pre_path, char *full_command)
{
    char **command_pipe = my_strtok(full_command, "|");
    int nb_command = my_arrlen(command_pipe);
    pid_t pids[nb_command];
    int return_status = 0;

    return_status = execute_pipe(env, pre_path, command_pipe, pids);
    for (int i = 0; i < nb_command; i++)
        waitpid(pids[i], NULL, 0);
    return return_status;
}
