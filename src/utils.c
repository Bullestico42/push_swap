/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:11:59 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:43:18 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tnumbers(t_num *num)
{
	if (num && num->tnumbers)
	{
		free(num->tnumbers);
		num->tnumbers = NULL;
	}
}

void	fill_stack(t_stack *stack, t_num *array)
{
	int	i;

	i = 0;
	while (i < array->size)
	{
		stack->a[i] = array->tnumbers[i];
		i++;
	}
	stack->size_a = array->size;
	stack->size_b = 0;
}

void	sort_two(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

void	sort_stack(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	if (stack->size_a == 2)
		sort_two(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a <= 5)
		sort_five(stack);
	else
		radix_sort(stack);
}

int	is_array_sorted(t_stack *stack)
{
	int	i;

	if (stack->size_a <= 1)
		return (1);
	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
