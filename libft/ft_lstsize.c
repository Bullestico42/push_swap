/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:00:02 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/26 23:20:38 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		(*lst) = (*lst)->next;
	}
	return (count);
}
