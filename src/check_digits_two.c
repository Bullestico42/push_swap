/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 02:21:43 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 16:27:00 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_digits_two(char **argv, t_num *num)
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
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (!fill_tab_two(argv, num))
		return (0);
	if (!check_double_two(num, num->size))
		return (0);
	return (1);
}

static int	process_number(char *str, t_num *num, int x)
{
	long	num_value;

	num_value = ft_atol(str);
	if (num_value > INT_MAX || num_value < INT_MIN)
	{
		free(num->tnumbers);
		return (0);
	}
	num->tnumbers[x] = (int)num_value;
	return (1);
}

int	fill_tab_two(char **argv, t_num *num)
{
	int	i;
	int	x;

	x = 0;
	while (argv[num->size + 1] != NULL)
		num->size++;
	num->tnumbers = (int *)malloc(sizeof(int) * num->size);
	if (!num->tnumbers)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!process_number(argv[i], num, x))
			return (0);
		i++;
		x++;
	}
	return (1);
}

int	check_double_two(t_num *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size && tab->tnumbers[i])
	{
		j = i + 1;
		while (j < size && tab->tnumbers[j])
		{
			if (tab->tnumbers[i] == tab->tnumbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
