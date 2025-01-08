/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:24:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/08 17:55:15 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_list **a, int *tab)
{
	int	element;
	int	lst_size;

	lst_size = ft_lstsize(*a);
	element = find_element_to_push(a, tab);
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
}

void	sort_b(t_list **b, t_list **a)
{
	t_list	*b_current;
	t_list	*a_current;
	int		index;
	int		position;

	b_current = *b;
	a_current = *a;
	position = -1;
	index = 0;
	while (b_current->next != NULL || position == -1)
	{
		if (b_current->content < a_current->content)
			position = index;
		index++;
		b_current = b_current->next;
	}
	while (position > 0)
	{
		*b = ft_rotate(b, *b, "b");
		print_list(*b, "b");
		position--;
	}
}

void	push_chunk_to_b(t_list **a, t_list **b, int *tab)
{
	int	tab_size;
	int	i;

	tab_size = get_tabsize(tab);
	i = 0;
	while (i < tab_size)
	{
		move_to_top(a, tab);
		if (ft_lstsize(*b) > 1)
			sort_b(b, a);
		*a = ft_push(*a, b, "a");
		i++;
	}
}
