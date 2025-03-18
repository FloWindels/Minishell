/*
** EPITECH PROJECT, 2025
** execute_command
** File description:
** use for find and execute the command in the shell
*/

#include "my.h"
#include "mysh.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void clean_command(char **command)
{
    while (*command) {
        *command = rm_char_form_str(*command, '\t');
        *command = rm_char_form_str(*command, '\"');
        *command = rm_char_form_str(*command, ' ');
        *command = rm_char_form_str(*command, '$');
        command++;
    }
}

int execute_fork(pid_t *pid, char **command, char **env)
{
    int status = 0;

    clean_command(command);
    switch (*pid) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            status = execve(command[0], command, env);
    }
}

char *find_command(char **paths, char *prompt)
{
    int status = 0;
    char *full_command = NULL;

    prompt = my_strcat("/", prompt);
    while (*paths) {
        full_command = my_strcat(*paths, prompt);
        status = open(full_command, O_RDONLY);
        if (status != -1) {
            free(prompt);
            return full_command;
        }
        free(full_command);
        paths++;
    }
    free(prompt);
    return NULL;
}

char *find_paths(char *prompt, char **env)
{
    char **paths = NULL;
    char *new_prompt = NULL;

    while (*env) {
        if (my_strncmp(*env, "PATH", 3) == 0) {
            paths = my_strtok(*env, "=:");
            break;
        }
        free_array(paths);
        env++;
    }
    if (paths == NULL)
        return prompt;
    new_prompt = find_command(paths, prompt);
    if (new_prompt) {
        free(prompt);
        prompt = new_prompt;
    }
    free_array(paths);
    return prompt;
}

int execute_command(char **command, char **env)
{
    int status = 0;
    pid_t pid = 0;

    if (command[0][0] != '/' && command[0][0] != '.')
        command[0] = find_paths(command[0], env);
    pid = fork();
    status = execute_fork(&pid, command, env);
    if (status == -1) {
        free_array(command);
        return -1;
    }
    waitpid(pid, &status, 0);
    if (status != 0)
        status = print_error_code(status, command);
    free_array(command);
    return status;
}
