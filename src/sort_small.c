/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:12:31 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/05 19:52:57 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_smallest_to_top(t_stack *stack);

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
	if (stack->size_a < 4)
		return ;
	move_smallest_to_top(stack);
	if (!is_sorted(stack) && stack->b)
		pb(stack);
	sort_three(stack);
	if (stack->b)
		pa(stack);
}

void	sort_five(t_stack *stack)
{
	if (stack->size_a < 5)
		sort_four(stack);
	move_smallest_to_top(stack);
	if (!is_sorted(stack) && stack->b)
		pb(stack);
	sort_four(stack);
	if (stack->b)
		pa(stack);
}

static void	move_smallest_to_top(t_stack *stack)
{
	int	pos;
	int	i;

	pos = find_smallest_position(stack);
	if (pos <= stack->size_a / 2)
	{
		i = 0;
		while (i < pos)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack->size_a - pos)
		{
			rra(stack);
			i++;
		}
	}
}
