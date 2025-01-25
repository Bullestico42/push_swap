/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:22:08 by apiscopo          #+#    #+#             */
/*   Updated: 2025/01/24 20:51:03 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_SIZE 500

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	max_size;
}	t_stack;

typedef struct s_num
{
	int	*tnumbers;
	int	size;
}	t_num;

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

/* Fonctions de vérification */
int		check_digits(char *nums, t_num *num);
int		check_digits_two(char **argv, t_num *num);
int		check_double(t_num *num);
int		check_double_two(t_num *tab, int size);
int		fill_tab_two(char **argv, t_num *num);
int		fill_tab(char **tab_digit, t_num *tab, char *num);

/* Fonctions utilitaires */
void	error_exit(t_stack *stack);
void	init_stacks(t_stack *stack);
void	free_stacks(t_stack *stack);
void	free_tnumbers(t_num *num);
void	free_tab_digit(char **tab_digit);
long	ft_atol(const char *str);
void	fill_stack(t_stack *stack, t_num *array);
void	sort_stack(t_stack *stack);

#endif
