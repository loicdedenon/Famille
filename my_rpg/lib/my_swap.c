/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** my swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
