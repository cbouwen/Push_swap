/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:41:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/08/11 18:37:18 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack_a(t_stacks *stacks, int *int_array, size_t size)
{
	size_t	i;
	size_t	j;
	int		index;

	i = -1;
	while (++i < size)
	{
		j = -1;
		index = 1;
		while (++j < size)
			if (int_array[j] < int_array[i])
				index++;
		stacks->a->array[i] = index;
	}
}

static int	ft_init_stacks(t_stacks *stacks, int *int_array, size_t size)
{
	stacks->a = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->a)
		return (0);
	stacks->b = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->b)
		return (0);
	stacks->a->array = (int *)malloc(sizeof(int) * size);
	if (!stacks->a->array)
		return (0);
	stacks->b->array = (int *)malloc(sizeof(int) * size);
	if (!stacks->b->array)
		return (0);
	ft_init_stack_a(stacks, int_array, size);
	stacks->a->size = size;
	while (size--)
		stacks->b->array[size] = -1;
	stacks->b->size = 0;
	return (1);
}

static int	*ft_init_int_array(int *int_array, size_t size, char **args)
{
	while (size--)
		int_array[size] = ft_atol(args[size]);
	return (int_array);
}

void	ft_parse(t_stacks *stacks, char **argv, size_t size)
{
	int	*int_array;

	if (!ft_numbers_ok(size, argv))
		ft_error(NULL);
	int_array = (int *)malloc(size * sizeof(int));
	if (!int_array)
		ft_error(NULL);
	int_array = ft_init_int_array(int_array, size, argv);
	if (!ft_doubles(int_array, size))
		ft_error(int_array);
	if (!ft_init_stacks(stacks, int_array, size))
		ft_error(int_array);
	free(int_array);
}
