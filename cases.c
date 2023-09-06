/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:33:43 by cbouwen           #+#    #+#             */
/*   Updated: 2023/08/23 17:08:37 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotates everything up
static void	case1(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->b->array[0] != sp.from_val
		&& stacks->a->array[0] != sp.to_val)
		rotate(stacks, RR);
	while (stacks->b->array[0] != sp.from_val)
		rotate(stacks, RB);
	while (stacks->a->array[0] != sp.to_val)
		rotate(stacks, RA);
}

//rotates everything down
static void	case2(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->b->array[0] != sp.from_val
		&& stacks->a->array[0] != sp.to_val)
		rotate(stacks, RRR);
	while (stacks->b->array[0] != sp.from_val)
		rotate(stacks, RRB);
	while (stacks->a->array[0] != sp.to_val)
		rotate(stacks, RRA);
}

//a goes up, b goes down
static void	case3(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->b->array[0] != sp.from_val)
		rotate(stacks, RB);
	while (stacks->a->array[0] != sp.to_val)
		rotate(stacks, RRA);
}

//a goes down, b goes up
static void	case4(t_stacks *stacks, t_sorting_params sp)
{
	while (stacks->b->array[0] != sp.from_val)
		rotate(stacks, RRB);
	while (stacks->a->array[0] != sp.to_val)
		rotate(stacks, RA);
}

void	execute_case(t_stacks *stacks, t_sorting_params sp)
{
	if (sp.case_number == CASE1)
		case1(stacks, sp);
	else if (sp.case_number == CASE2)
		case2(stacks, sp);
	else if (sp.case_number == CASE3)
		case3(stacks, sp);
	else if (sp.case_number == CASE4)
		case4(stacks, sp);
}
