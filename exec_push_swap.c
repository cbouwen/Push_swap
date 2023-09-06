/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:27:31 by cbouwen           #+#    #+#             */
/*   Updated: 2023/08/17 13:43:54 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_swap(t_stack *stack)
{
	int	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	swap(t_stacks *stacks, int a)
{
	if (a == SA)
		exec_swap(stacks->a);
	if (a == SB)
		exec_swap(stacks->b);
	if (a == SS)
	{
		exec_swap(stacks->a);
		exec_swap(stacks->b);
	}
	ft_print_execs(a);
}

static void	exec_push(t_stack *stack1, t_stack *stack2)
{
	int	temp;

	temp = stack2->array[0];
	base_rotate(stack2);
	stack2->size -= 1;
	stack1->size += 1;
	base_reverse_rotate(stack1);
	stack1->array[0] = temp;
}

void	push(t_stacks *stacks, int a)
{
	if (a == PA)
		exec_push(stacks->a, stacks->b);
	if (a == PB)
		exec_push(stacks->b, stacks->a);
	ft_print_execs(a);
}
