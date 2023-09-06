/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:11:25 by cbouwen           #+#    #+#             */
/*   Updated: 2023/08/17 13:22:40 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	base_rotate(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size - 1)
		stack->array[i] = stack->array[i + 1];
}

void	base_reverse_rotate(t_stack *stack)
{
	int	i;

	i = stack->size;
	while (--i > 0)
		stack->array[i] = stack->array[i - 1];
}

static void	exec_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->array[0];
	base_rotate(stack);
	stack->array[stack->size - 1] = temp;
}

static void	exec_reverse_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->array[stack->size - 1];
	base_reverse_rotate(stack);
	stack->array[0] = temp;
}

void	rotate(t_stacks *stacks, int a)
{
	if (a == RA)
		exec_rotate(stacks->a);
	if (a == RB)
		exec_rotate(stacks->b);
	if (a == RR)
	{
		exec_rotate(stacks->a);
		exec_rotate(stacks->b);
	}
	if (a == RRA)
		exec_reverse_rotate(stacks->a);
	if (a == RRB)
		exec_reverse_rotate(stacks->b);
	if (a == RRR)
	{
		exec_reverse_rotate(stacks->a);
		exec_reverse_rotate(stacks->b);
	}
	ft_print_execs(a);
}
