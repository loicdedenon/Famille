/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include "struct.h"

#ifndef MY_H_
    #define MY_H_

    #ifndef M_PI
        #define M_PI 3.14159265358979323846
    #endif

    #include <dirent.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <signal.h>
    #include <ctype.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <math.h>
    #include "struct.h"
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_put_octal(int nb);
void binary(unsigned int nb);
int my_put_unsigned_decimal(unsigned int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char **my_str_to_word_array(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(const char *str);
char *my_strtok(char *str, const char *del);
int my_atoi(char *str);
int num_addon(int c);
int my_isnum(int c);
int alnum_addon(char c);
int my_isalnum(char c);
int alpha_addon(char c);
int isalpha_ext(char c);
int my_isalpha(char c);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void my_hexadecimalup(unsigned int nb);
void my_hexadecimaldown(unsigned int nb);
char *my_strclean(char *str);
int my_printf(const char *format, ...);
char **copy_env(char **envp);
void print_env(all_t all);
void cd_builtin(all_t all);
void handle_signals(void);
char *get_truepath(char *file, char *path);
int builtin(all_t all);
char **my_setenv(all_t all);
int get_argc(char **argc);
char **my_unsetenv(all_t all);
char **parser(char const *str, char d);
int semicolons_detector(char *line);
int error_check(all_t all);
char **setenv_two(all_t all);
int find_slashes(char *str);
int fenetre(void);

#endif
