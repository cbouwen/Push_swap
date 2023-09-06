/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:30:44 by cbouwen           #+#    #+#             */
/*   Updated: 2023/09/06 12:28:28 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_numbers_ok(size_t size, char **argv)
{
	char	*ptr;
	int		sign;
	long	num;

	ptr = NULL;
	while (size--)
	{
		num = 0;
		sign = 1;
		ptr = argv[size];
		if (*ptr == '-')
		{
			sign = -1;
			ptr++;
		}
		while (*ptr)
		{
			num = num * 10 + (*ptr - '0');
			if (!ft_isdigit(*ptr) || sign * num > INT_MAX || sign
				* num < INT_MIN)
				return (false);
			ptr++;
		}
	}
	return (true);
}

bool	ft_doubles(int *int_array, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (int_array[i] == int_array[j])
				return (false);
	}
	return (true);
}

void	ft_error(void *ptr)
{
	if (ptr)
		free(ptr);
	write(2, "Error\n", 6);
	exit(0);
}
