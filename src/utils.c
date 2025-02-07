/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:11:59 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/30 01:15:58 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort_two(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

void	sort_stack(t_stack *stack)
{
	stack->b = malloc(sizeof(int) * stack->size_a);
	if (!stack->b)
		return ;
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

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_tab_digit(char **tab_digit)
{
	int	i;

	i = 0;
	while (tab_digit[i])
		free(tab_digit[i++]);
	free(tab_digit);
}
