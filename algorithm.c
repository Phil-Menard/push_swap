/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:24:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/08 17:00:46 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk_to_b(t_list **a, t_list **b, int *tab)
{
	int	element;
	int	lst_size;
	int	tab_size;
	int	i;

	tab_size = get_tabsize(tab);
	i = 0;
	while (i < tab_size)
	{
		lst_size = ft_lstsize(*a);
		element = find_element_to_push(a, tab);
		/* ft_printf("element : %d\n", element);
		ft_printf("lst_size : %d\n", lst_size); */
		if (element >= (lst_size / 2) + 1)
		{
			while (element < lst_size)
			{
				*a = ft_reverse(a, *a, "a");
				element++;
			}
		}
		else
		{
			while (element > 0)
			{
				*a = ft_rotate(a, *a, "a");
				element--;
			}
		}
		*a = ft_push(*a, b, "a");
		i++;
	}
}
