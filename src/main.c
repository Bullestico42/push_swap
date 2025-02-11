/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:56 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/11 19:52:16 by apiscopo         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	stack.size_a = 0;
	stack.size_b = 0;
	if (argc == 2)
	{
		if (!check_digits(argv[1], &stack))
			error_exit(&stack);
	}
	else if (!check_digits_two(argv, &stack))
		error_exit(&stack);
	sort_stack(&stack);
	free_stacks(&stack);
	return (0);
}
