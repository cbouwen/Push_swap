/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:34:17 by cbouwen           #+#    #+#             */
/*   Updated: 2023/09/06 12:11:04 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_execs(int a)
{
	static char	*executable[11];

	executable[SA] = "sa\n";
	executable[SB] = "sb\n";
	executable[SS] = "ss\n";
	executable[PA] = "pa\n";
	executable[PB] = "pb\n";
	executable[RA] = "ra\n";
	executable[RB] = "rb\n";
	executable[RR] = "rr\n";
	executable[RRA] = "rra\n";
	executable[RRB] = "rrb\n";
	executable[RRR] = "rrr\n";
	ft_printf("%s", executable[a]);
}

static void	free_stacks(t_stacks *stacks)
{
	free(stacks->a->array);
	free(stacks->b->array);
	free(stacks->a);
	free(stacks->b);
}

static int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a->size - 1)
	{
		if (stacks->a->array[i] > stacks->a->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	sort(t_stacks *stacks, int argc)
{
	if (!is_sorted(stacks))
		return ;
	if (argc == 2)
		swap(stacks, SA);
	if (argc == 3)
		sort_three(stacks);
	else
	{
		phase1(stacks);
		phase2(stacks);
		finalize(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2 || argc > 501)
		ft_error(NULL);
	ft_parse(&stacks, argv + 1, (size_t)--argc);
	sort(&stacks, argc);
	free_stacks(&stacks);
}
