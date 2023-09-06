/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:36:29 by cbouwen           #+#    #+#             */
/*   Updated: 2023/09/06 15:06:14 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define CASE1 0
# define CASE2 1
# define CASE3 2
# define CASE4 3

typedef struct s_sorting_params
{
	int		cost;
	int		case_number;
	int		from_pos;
	int		from_val;
	int		to_pos;
	int		to_val;
}			t_sorting_params;

typedef struct s_stack
{
	int		*array;
	int		size;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

void		ft_parse(t_stacks *stacks, char **argv, size_t size);
long		ft_atol(const char *nptr);
void		ft_error(void *ptr);
bool		ft_doubles(int *int_array, size_t size);
bool		ft_numbers_ok(size_t size, char **argv);
int			ft_isdigit(int c);
void		swap(t_stacks *stacks, int a);
void		rotate(t_stacks *stacks, int a);
void		push(t_stacks *stacks, int a);
void		base_rotate(t_stack *stack);
void		base_reverse_rotate(t_stack *stack);
void		sort_three(t_stacks *stacks);
void		quicksort(t_stacks *stacks);
void		fullswap(t_stacks *stacks);
void		ft_print_execs(int a);
void		execute_case(t_stacks *stacks, t_sorting_params sp);
void		phase2(t_stacks *stacks);
void		phase1(t_stacks *stacks);
void		finalize(t_stacks *stacks);

#endif
