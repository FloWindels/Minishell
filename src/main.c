/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute_all(char **command, char **env, char **pre_path)
{
    if (my_strcmp(command[0], "cd") == 0)
        return execute_cd(command, env, pre_path);
    return execute_command(command, env);
}

int check_utils(char **command, char **env,
    char **pre_path, char *full_command)
{
    for (int i = 0; command[i]; i++) {
        if (command[i][0] == '|')
            return init_pipe(env, pre_path, full_command);
        if (command[i][0] == '>' || command[i][0] == '<')
            return handle_redirection(env, pre_path, full_command);
    }
    return execute_all(command, env, pre_path);
}

int execute(char *result, char **env, char **pre_path)
{
    char **full_command = my_strtok(result, "'\n''\t';");
    char **command = NULL;
    int return_status = -1;

    if (!full_command)
        return -1;
    while (*full_command) {
        command = my_strtok(*full_command, " ");
        if (!command)
            return -1;
        return_status = check_utils(command, env, pre_path, *full_command);
        full_command++;
    }
    return return_status;
}

char *get_prompt_user(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (isatty(STDOUT_FILENO))
        my_printf("$> ");
    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return NULL;
    }
    return line;
}

int main(int argc, char **argv, char **env)
{
    char *result = NULL;
    int status = 0;
    char *previous_path = NULL;

    while (1) {
        result = get_prompt_user();
        if (result == NULL)
            break;
        if (my_strcmp(result, "\n") != 0){
            result = clean_str(result, "\t");
            status = execute(result, env, &previous_path);
        }
        if (status == -1) {
            free(previous_path);
            return 84;
        }
        free(result);
    }
    free(previous_path);
    return status;
}
