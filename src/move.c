/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:23:18 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:52:58 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	ft_putendl_fd("sa", 1);
}

void	pa(t_stack *stack)
{
	int	i;

	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
	ft_putendl_fd("pb", 1);
}

void	ra(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a < 2)
		return ;
	temp = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = temp;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a < 2)
		return ;
	temp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
	ft_putendl_fd("rra", 1);
}
