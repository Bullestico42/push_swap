/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:28:24 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:53:31 by apiscopo         ###   ########.fr       */
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

void	free_tab_digit(char **tab_digit)
{
	int	i;

	i = 0;
	while (tab_digit[i])
		free(tab_digit[i++]);
	free(tab_digit);
}

int	check_digits(char *nums, t_num *num)
{
	char	**tab_digit;
	int		word_count;

	word_count = count_words(nums, ' ');
	if (word_count < 2)
		return (0);
	tab_digit = ft_split(nums, ' ');
	if (!tab_digit)
		return (0);
	if (!fill_tab(tab_digit, num, nums))
	{
		free_tab_digit(tab_digit);
		return (0);
	}
	if (!check_double(num))
	{
		free_tab_digit(tab_digit);
		return (0);
	}
	free_tab_digit(tab_digit);
	return (1);
}

int	check_double(t_num *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->size)
	{
		j = i + 1;
		while (j < tab->size)
		{
			if (tab->tnumbers[i] == tab->tnumbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_tab(char **tab_digit, t_num *tab, char *num)
{
	int		i;
	long	nums;

	tab_digit = ft_split(num, ' ');
	if (!tab_digit)
		return (0);
	while (tab_digit[tab->size])
		tab->size++;
	tab->tnumbers = (int *)malloc(sizeof(int) * tab->size);
	if (!tab->tnumbers)
		return (free_tab_digit(tab_digit), 0);
	i = 0;
	while (i < tab->size)
	{
		nums = ft_atol(tab_digit[i]);
		if (nums > INT_MAX || nums < INT_MIN)
		{
			free_tnumbers(tab);
			return (free_tab_digit(tab_digit), 0);
		}
		tab->tnumbers[i] = (int)nums;
		i++;
	}
	return (free_tab_digit(tab_digit), 1);
}
