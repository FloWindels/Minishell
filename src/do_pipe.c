/*
** EPITECH PROJECT, 2025
** pipe
** File description:
** execute command with a pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

void handle_pipe(int i, int *prev_pipe, int nb_command, int pipefd[2])
{
    if (i > 0) {
        dup2(*prev_pipe, STDIN_FILENO);
        close(*prev_pipe);
    }
    if (i < nb_command - 1) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
    }
}

int handle_pid(int i, int nb_command, int pipefd[2], pid_t *pid)
{
    if (i < nb_command - 1)
        if (pipe(pipefd) == -1)
            return 84;
    *pid = fork();
    if (*pid == -1)
        return 84;
    return 0;
}

void do_in_parent(int pipefd[2], int *prev_pipe)
{
    close(pipefd[1]);
    if (*prev_pipe != -1)
        close(*prev_pipe);
    *prev_pipe = pipefd[0];
}

int do_in_child(int i, char **command_pipe, char **env, char **pre_path)
{
    int nb_command = my_arrlen(command_pipe);
    int return_status = 0;

    return_status = execute_all(my_strtok(command_pipe[i], " "),
    env, pre_path);
    exit(return_status);
    return return_status;
}

int execute_pipe(char **env, char **pre_path, char **command_pipe, pid_t *pids)
{
    int nb_command = my_arrlen(command_pipe);
    int prev_pipe = -1;
    int return_status = 0;
    int pipefd[2];
    pid_t pid;

    for (int i = 0; i < nb_command; i++) {
        if (handle_pid(i, nb_command, pipefd, &pid) == 84)
            return 84;
        if (pid == 0) {
            handle_pipe(i, &prev_pipe, nb_command, pipefd);
            return_status = do_in_child(i, command_pipe, env, pre_path);
        } else {
            pids[i] = pid;
            do_in_parent(pipefd, &prev_pipe);
        }
    }
    return return_status;
}
