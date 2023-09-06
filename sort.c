/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:26:11 by cbouwen           #+#    #+#             */
/*   Updated: 2023/09/06 13:22:32 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(t_stacks *stacks)
{
	if (stacks->a->array[0] > stacks->a->array[1]
		&& stacks->a->array[0] > stacks->a->array[2])
		return (stacks->a->array[0]);
	if (stacks->a->array[1] > stacks->a->array[0]
		&& stacks->a->array[1] > stacks->a->array[2])
		return (stacks->a->array[1]);
	if (stacks->a->array[2] > stacks->a->array[1]
		&& stacks->a->array[2] > stacks->a->array[0])
		return (stacks->a->array[2]);
	return (0);
}

void	finalize(t_stacks *stacks)
{
	if (stacks->a->array[0] > stacks->a->size / 2)
		while (stacks->a->array[0] != 1)
			rotate(stacks, RA);
	else
		while (stacks->a->array[0] != 1)
			rotate(stacks, RRA);
}

void	sort_three(t_stacks *stacks)
{
	int	highest_value;

	highest_value = find_highest(stacks);
	if (stacks->a->array[0] == highest_value)
		rotate(stacks, RA);
	else if (stacks->a->array[1] == highest_value)
		rotate(stacks, RRA);
	if (stacks->a->array[0] > stacks->a->array[1])
		swap(stacks, SA);
}

void	phase1(t_stacks *stacks)
{
	while (stacks->a->size > 3)
		push(stacks, PB);
	sort_three(stacks);
}
