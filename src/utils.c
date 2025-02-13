/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:11:59 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/11 21:01:54 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_exit(t_stack *stack)
{
	free_stacks(stack);
	exit(1);
}

void	free_stacks(t_stack *stack)
{
	if (stack && stack->a)
		free(stack->a);
	if (stack && stack->b)
		free(stack->b);
	stack->a = NULL;
	stack->b = NULL;
	exit(0);
}

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

void	free_tab_digit(char **tab_digit)
{
	int	i;

	i = 0;
	while (tab_digit[i])
		free(tab_digit[i++]);
	free(tab_digit);
}
