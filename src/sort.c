/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:12:31 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:47:26 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = stack->size_a - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	*temp;
	int	count;

	temp = malloc(sizeof(int) * stack->size_a);
	if (!temp)
		return ;
	i = -1;
	while (++i < stack->size_a)
		temp[i] = stack->a[i];
	i = -1;
	while (++i < stack->size_a)
	{
		count = 0;
		j = -1;
		while (++j < stack->size_a)
			if (temp[i] > temp[j])
				count++;
		stack->a[i] = count;
	}
	free(temp);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	index_stack(stack);
	max_bits = get_max_bits(stack);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack->size_a;
		while (j < size)
		{
			if ((stack->a[0] >> i) & 1)
				ra(stack);
			else
				pb(stack);
			j++;
		}
		while (stack->size_b)
			pa(stack);
		i++;
	}
}
