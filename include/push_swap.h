/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:08 by apiscopo          #+#    #+#             */
/*   Updated: 2025/02/11 21:01:57 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_SIZE 500

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	max_size;
}	t_stack;

/* Mouvements de base */
void	sa(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);

/* Fonctions de tri */
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	radix_sort(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_array_sorted(t_stack *stack);

/* Fonctions de vérification */
int		check_digits(char *nums, t_stack *stack);
int		check_digits_two(char **argv, t_stack *stack);
int		check_numbers(t_stack *stack);
int		check_is_digits(char **tab);
int		check_double_two(t_stack *stack);
int		fill_tab_two(char **argv, t_stack *stack);
int		fill_tab(char **tab_digit, t_stack *stack);

/* Fonctions utilitaires */
void	error_exit(t_stack *stack);
void	free_stacks(t_stack *stack);
void	free_tab_digit(char **tab_digit);
long	ft_atol(const char *str);
void	sort_stack(t_stack *stack);

#endif
