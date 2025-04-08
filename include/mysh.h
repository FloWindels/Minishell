/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef MYSH_
    #define MYSH_

    #include <sys/wait.h>
typedef struct env_elements_s {
    char **path;
} env_elements_t;

int execute_command(char **command, char **env);
int print_error_code(int code, char **command);
int execute_cd(char **command, char **env, char **pre_path);
int print_error_code(int code, char **command);
int init_pipe(char **env, char **pre_path, char *full_command);
int handle_redirection(char **env, char **pre_path, char *full_command);
int simple_redirection(char **env, char **pre_path,
    char *full_command, int redi);
int execute_all(char **command, char **env, char **pre_path);
int execute_pipe(char **env, char **pre_path, char **command_pipe,
    pid_t *pids);

#endif /* MYSH_ */
