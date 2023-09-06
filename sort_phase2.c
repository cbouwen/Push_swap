/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:33:43 by cbouwen           #+#    #+#             */
/*   Updated: 2023/09/06 12:27:53 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_min_pos_val(t_stacks stacks, t_sorting_params *sp)
{
	int	posa;

	posa = -1;
	while (++posa < stacks.a->size)
	{
		if (stacks.a->array[posa] < sp->to_val)
		{
			sp->to_pos = posa;
			sp->to_val = stacks.a->array[posa];
		}
	}
}

static void	ft_find_pos(int posb, t_stacks *stacks, t_sorting_params *sp)
{
	int	posa;

	posa = -1;
	sp->to_pos = -1;
	sp->to_val = INT_MAX;
	while (++posa < stacks->a->size)
	{
		if (stacks->b->array[posb] < stacks->a->array[posa]
			&& stacks->a->array[posa] < sp->to_val)
		{
			sp->to_val = stacks->a->array[posa];
			sp->to_pos = posa;
		}
	}
	if (sp->to_pos == -1)
		ft_get_min_pos_val(*stacks, sp);
}

static void	ft_sorting_params(int posb, t_stacks *stacks, t_sorting_params *sp)
{
	int	i;
	int	costs[4];

	sp->from_pos = posb;
	ft_find_pos(posb, stacks, sp);
	costs[CASE1] = ft_max(sp->from_pos, sp->to_pos);
	costs[CASE2] = ft_max(stacks->b->size - sp->from_pos, stacks->a->size
			- sp->to_pos);
	costs[CASE3] = (sp->from_pos + stacks->a->size - sp->to_pos);
	costs[CASE4] = (stacks->b->size - sp->from_pos + sp->to_pos);
	i = -1;
	sp->cost = INT_MAX;
	while (++i < 4)
	{
		if (costs[i] < sp->cost)
		{
			sp->from_val = stacks->b->array[posb];
			sp->case_number = i;
			sp->cost = costs[i];
		}
	}
}

static void	ft_calculate(t_stacks *stacks, t_sorting_params *sp)
{
	int					posb;
	t_sorting_params	temp;

	posb = 0;
	ft_sorting_params(posb, stacks, sp);
	while (++posb < stacks->b->size)
	{
		if (posb < sp->cost || posb > stacks->b->size - sp->cost)
		{
			ft_sorting_params(posb, stacks, &temp);
			if (temp.cost < sp->cost)
				*sp = temp;
		}
	}
}

void	phase2(t_stacks *stacks)
{
	t_sorting_params	sp;

	while (stacks->b->size != 0)
	{
		ft_calculate(stacks, &sp);
		execute_case(stacks, sp);
		push(stacks, PA);
	}
}
