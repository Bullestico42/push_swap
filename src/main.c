/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:56 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 16:57:18 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stacks(t_stack *stack)
{
	stack->a = malloc(sizeof(int) * MAX_SIZE);
	stack->b = malloc(sizeof(int) * MAX_SIZE);
	if (!stack->a || !stack->b)
		error_exit(stack);
	stack->size_a = 0;
	stack->size_b = 0;
	stack->max_size = MAX_SIZE;
}

void	error_exit(t_stack *stack)
{
	free_stacks(stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_stacks(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_num	num;

	if (argc < 2)
		return (0);
	init_stacks(&stack);
	num.size = 0;
	num.tnumbers = NULL;
	if (argc == 2)
	{
		if (!check_digits(argv[1], &num))
			error_exit(&stack);
	}
	else if (!check_digits_two(argv, &num))
		error_exit(&stack);
	fill_stack(&stack, &num);
	free_tnumbers(&num);
	sort_stack(&stack);
	free_stacks(&stack);
	return (0);
}
