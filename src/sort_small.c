/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:12:31 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:51:26 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_smallest_position(t_stack *stack)
{
	int	smallest;
	int	smallest_pos;
	int	i;

	if (stack->size_a == 0)
		return (-1);
	smallest = stack->a[0];
	smallest_pos = 0;
	i = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i] < smallest)
		{
			smallest = stack->a[i];
			smallest_pos = i;
		}
		i++;
	}
	return (smallest_pos);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a < 3)
		return ;
	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	sort_four(t_stack *stack)
{
	int	smallest_pos;

	smallest_pos = find_smallest_position(stack);
	while (smallest_pos > 0)
	{
		if (smallest_pos <= 2)
			ra(stack);
		else
			rra(stack);
		smallest_pos = (smallest_pos - 1 + 4) % 4;
	}
	pb(stack);
	sort_three(stack);
	pa(stack);
}

void	sort_five(t_stack *stack)
{
	int	smallest_pos;

	smallest_pos = find_smallest_position(stack);
	while (smallest_pos > 0)
	{
		if (smallest_pos <= 2)
			ra(stack);
		else
			rra(stack);
		smallest_pos = (smallest_pos - 1 + 5) % 5;
	}
	pb(stack);
	sort_four(stack);
	pa(stack);
}
