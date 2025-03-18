/*
** EPITECH PROJECT, 2025
** excute cd
** File description:
** implement the bulid-in of cd
*/
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char **find_home(char **env)
{
    char **arr_path_home = NULL;
    char *path_home = NULL;

    while (*env) {
        if (my_strncmp(*env, "HOME", 3) == 0) {
            arr_path_home = my_strtok(*env, "=");
            break;
        }
        env++;
    }
    if (arr_path_home == NULL) {
        my_printf_error("cd: No home directory.\n");
        return NULL;
    }
    return arr_path_home;
}

int do_cd_alone(char **previous_path, char **command, char **env)
{
    int status = 0;
    char **home = find_home(env);

    free(*previous_path);
    *previous_path = getcwd(NULL, 0);
    chdir(home[1]);
    free_array(command);
    free_array(home);
    return status;
}

int do_cd_prev(char **previous_path, char **command)
{
    char *tmp_path = getcwd(NULL, 0);
    int status = 0;

    if (*previous_path == NULL) {
        my_printf_error(": No such file or directory.\n");
        free_array(command);
        free(tmp_path);
        return -2;
    }
    chdir(*previous_path);
    free(*previous_path);
    *previous_path = tmp_path;
    free_array(command);
    return status;
}

int execute_cd(char **command, char **env, char **pre_path)
{
    if (my_arrlen(command) == 1) {
        return do_cd_alone(pre_path, command, env);
    }
    if (my_strcmp(command[1], "-") == 0) {
        return do_cd_prev(pre_path, command);
    }
    free(*pre_path);
    *pre_path = getcwd(NULL, 0);
    if (chdir(command[1]) == -1) {
        my_printf_error("%s: No such file or directory.\n", command[1]);
        free_array(command);
        return 1;
    }
    free_array(command);
    return 0;
}
