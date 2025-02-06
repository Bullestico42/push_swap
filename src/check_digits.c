/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:28:24 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/05 18:12:59 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

int	check_digits(char *argv, t_stack *stack)
{
	char	**tab_digit;

	if (!argv)
		return (0);
	stack->size_a = count_words(argv, ' ');
	tab_digit = ft_split(argv, ' ');
	if (!tab_digit)
		return (0);
	if (!fill_tab(tab_digit, stack))
		return (free_tab_digit(tab_digit), 0);
	if (!check_numbers(stack))
		return (free_tab_digit(tab_digit), 0);
	if (!check_is_digits(tab_digit))
		return (free_tab_digit(tab_digit), 0);
	free_tab_digit(tab_digit);
	return (1);
}

int	check_is_digits(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
			if (!ft_isdigit(tab[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int	check_numbers(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_tab(char **tab_digit, t_stack *stack)
{
	int		i;
	long	result;

	i = 0;
	stack->a = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->a)
		return (0);
	while (tab_digit[i])
	{
		result = ft_atol(tab_digit[i]);
		if (result > INT_MAX || result < INT_MIN)
			return (free_stacks(stack), 0);
		stack->a[i++] = (int)result;
	}
	if (i < 2)
		return (free_stacks(stack), 0);
	return (1);
}
