/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** e
*/

#include "./incluall.h"

#pragma once

char **split(char *raw_cmd, char *limit);
int if_split(char **cmd, size_t idx);
unsigned int my_decimal(int nb);
double my_expomaj_plus(double nb);
double my_expomaj_minus(double nb);
double my_expomaj(double nb);
double my_expomin_plus(double nb);
double my_expomin_minus(double nb);
double my_expomin(double nb);
int my_float2(double nb);
int my_float(double nb);
int my_hexamajletter(int nb);
unsigned int my_hexamaj(int nb);
int my_hexaminletter(int nb);
unsigned int my_hexamin(int nb);
unsigned int my_octet(int nb);
int my_printf(const char *format, ...);
int my_printf_suite(va_list list, const char *format, int i);
int my_printf_again(va_list list, const char *format, int i);
int my_printf_the_last(va_list list, const char *format, int i);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
char **my_str_to_word_array(char const *str, char sup);
int my_isalpha(char c);
int my_strlen(const char *str);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strcat(char *dest, const char *src);
char *get_next_line(const int fd);
int detect_end(char *str, char *new);
int exec_cmd(char *str);
int if_end(char *new);
int get_dir(char **tab, float mid);
int gesture(void);
typedef struct ResponseHeader{
    int value_id;
    int status;
    char* code_str;
    char *data; 
}ResponseHeader;
int send_command(char *command, ResponseHeader *response);
int forward(float horsepower);
int start(void);
int stop(void);
int info(void);
