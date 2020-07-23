#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

// # include "macro.h"
#include "../libft/header/libft.h"

typedef struct s_ps
{
	int *a;
	int lenA;
	int *b;
	int lenB;
	int option;
	int count;
} t_ps;

/*
** Push swap basic function
*/
void ft_push_init(t_ps *ps, int length);
int ft_push_read(t_ps *ps, int length, char **actor);
void ft_push_print(char *str, char flag, t_ps *ps);
int ft_push_exit(char *str, t_ps *ps);
int ft_push_check3(t_ps *ps);
/*
** Push swap operation function
*/
void ft_push_restruct(t_ps *ps, int **array, int *length, char flag);
void ft_push_construct(t_ps **ps, int *array, int length, char flag);
void ft_push_insert(int current, char flag, t_ps *ps);
void ft_push_remove(char flag, t_ps *ps);
int ft_push_check(t_ps *ps);
/*
** Push swap ascent function
*/
void ft_push_iterate(t_ps *ps, int count_step, char flag, int length);
void ft_push_ascent(t_ps *ps, char flag, int max, int current);
void ft_push_prev_ascent(t_ps *ps, char flag);

/*
** Push swap action
*/
void ft_push_r(t_ps *ps, char flag);
void ft_push_rr(t_ps *ps, char flag);
void ft_push_s(t_ps *ps, char flag);
void ft_push_pb(t_ps *ps);
void ft_push_pa(t_ps *ps);
void ft_push_rr_(t_ps *ps);
void ft_push_r_(t_ps *ps);
void ft_push_s_(t_ps *ps);

#endif
