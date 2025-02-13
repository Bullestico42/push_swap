/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 02:21:43 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/11 20:32:24 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digits_two(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || j > 11)
				return (ft_putendl_fd("Error", 2), 0);
			j++;
		}
		i++;
	}
	if (!fill_tab_two(argv, stack))
		return (0);
	if (!check_double_two(stack))
		return (0);
	return (1);
}

int	process_number(char *str, t_stack *stack, int x)
{
	long	num_value;

	num_value = ft_atol(str);
	if (num_value > INT_MAX || num_value < INT_MIN)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	stack->a[x] = (int)num_value;
	return (1);
}

int	fill_tab_two(char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	while (argv[stack->size_a + 1] != NULL)
		stack->size_a++;
	stack->a = malloc(sizeof(int) * stack->size_a);
	if (!stack->a)
		return (0);
	while (argv[i])
	{
		if (!process_number(argv[i], stack, i - 1))
			return (0);
		i++;
	}
	return (1);
}

int	check_double_two(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j++])
				return (ft_putendl_fd("Error", 2), 0);
		}
		i++;
	}
	return (1);
}