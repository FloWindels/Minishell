/*
** EPITECH PROJECT, 2025
** do_redirection
** File description:
** all the fonction for the redirection
*/

#include "my.h"
#include "mysh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

int witch_redi(char **command_redir, int redi)
{
    int fd = 0;

    if (redi == 0)
        fd = open(clean_str(command_redir[my_arrlen(command_redir) - 1],
        " '\t''\n'"), O_CREAT | O_WRONLY, 0664);
    if (redi == 1)
        fd = open(clean_str(command_redir[my_arrlen(command_redir) - 1],
        " '\t''\n'"), O_CREAT | O_APPEND | O_WRONLY, 0664);
    return fd;
}

int do_redirection(char **command_redir, char **env, char **pre_path, int fd)
{
    char **exe_command = NULL;
    int tmp_fd = dup(STDOUT_FILENO);

    if (tmp_fd == -1)
        return 84;
    if (my_arrlen(command_redir) >= 2) {
        exe_command = my_strtok(command_redir[0], " ");
        if (!exe_command)
            return 84;
        dup2(fd, STDOUT_FILENO);
        execute_all(exe_command, env, pre_path);
        dup2(tmp_fd, STDOUT_FILENO);
    }
}

int simple_redirection(char **env, char **pre_path,
    char *full_command, int redi)
{
    char **command_redir = my_strtok(full_command, ">");
    char *line = NULL;
    int fd = 0;

    if (!command_redir)
        return 84;
    fd = witch_redi(command_redir, redi);
    if (fd == -1) {
        free_array(command_redir);
        return 84;
    }
    do_redirection(command_redir, env, pre_path, fd);
    close(fd);
    free_array(command_redir);
    return 0;
}
