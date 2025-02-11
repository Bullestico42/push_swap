/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:50:30 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/11 20:52:16 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	process_atol_sign(const char *str, size_t *i)
{
	long	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' && str[*i + 1] != '-')
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atol(const char *str)
{
	size_t	i;
	long	sign;
	long	result;

	i = 0;
	result = 0;
	sign = process_atol_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
