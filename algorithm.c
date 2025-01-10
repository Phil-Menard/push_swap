/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:24:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/10 17:18:24 by pmenard          ###   ########.fr       */
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

void	change_order_in_b(t_list **b, int position)
{
	int	lst_size;

	lst_size = ft_lstsize(*b);
	if (position >= (lst_size / 2) + 1)
	{
		while (position < lst_size)
		{
			*b = ft_reverse(b, *b, "b");
			position++;
		}
	}
	else
	{
		while (position > 0)
		{
			*b = ft_rotate(b, *b, "b");
			position--;
		}
	}
}

void	sort_b(t_list **b)
{
	t_list	*current;
	int		bigger;
	int		index;

	bigger = get_bigger_element(b);
	current = *b;
	index = 0;
	while (*(int *)current->content != bigger)
	{
		index++;
		current = current->next;
	}
	change_order_in_b(b, index);
}

void	push_chunk_to_b(t_list **a, t_list **b, int *tab)
{
	int	tab_size;
	int	i;
	int	position;

	tab_size = get_tabsize(tab);
	i = 0;
	while (i < tab_size)
	{
		move_to_top(a, tab);
		//print_list(*b, "b");
		if (ft_lstsize(*b) > 1)
		{
			position = find_position(b, *a);
			change_order_in_b(b, position);
		}
		*a = ft_push(*a, b, "a");
		i++;
	}
}
