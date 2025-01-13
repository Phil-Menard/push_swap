/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:31:55 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/13 17:08:17 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_double(t_list **a, t_list **b)
{
	*a = ft_rotate(a, *a, "a", 1);
	*b = ft_rotate(b, *b, "b", 1);
	ft_printf("\n");
}

void	ft_reverse_double(t_list **a, t_list **b)
{
	*a = ft_reverse(a, *a, "a", 1);
	*b = ft_reverse(b, *b, "b", 1);
	ft_printf("r\n");
}
