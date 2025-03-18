/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** h file
*/

#ifndef MY_
    #define MY_

void my_putchar(char c);
int my_isneg(int nb);
long my_put_nbr(long nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n, int start);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_sort_int_array(int *tab, int size);
int check_lettre(const char *str, int i);
int check_number(const char *str, int i);
int my_getsign(char const *str);
int my_put_float(double n, int pre);
double my_round(double n, int pres);
int my_putnbr_base(long nbr, char const *base);
int my_put_long(unsigned long int nb);
int my_put_unsigned(long int nb);
int my_putnbr_sc(double n, long pre);
int nota_sc_cont(int dot, int nbcara);
double posi(double n);
int my_putnbr_e(double n, long pre);
int my_printf(const char *format, ...);
int my_print_char_arr(char **name);
int my_nb_file(char *name_file);
int my_file_alpha(char **name);
int my_arrlen(char **arr);
char **my_strtok(char *str, char *delimiters);
void free_array(char **array);
void my_putchar_error(char c);
int my_putstr_error(char const *str);
int my_printf_error(const char *format, ...);
char *my_strdup(char *src);
char *rm_char_form_str(char *src, char rm);
char *clean_str(char *src, char *rm_char);

#endif /* MY_ */
