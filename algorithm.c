/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:24:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/15 13:52:02 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adjust_lst(t_list **a, t_list **b, int *position, int *element)
{
	int	lst_size_a;
	int	lst_size_b;

	lst_size_a = ft_lstsize(*a);
	lst_size_b = ft_lstsize(*b);
	if (*position >= (lst_size_b / 2) + 1 && *element >= (lst_size_a / 2) + 1)
	{
		while (*position < lst_size_b && *element < lst_size_a)
		{
			ft_reverse_double(a, b);
			*element += 1;
			*position += 1;
		}
	}
	else if (*element < (lst_size_a / 2) + 1
		&& *position < (lst_size_b / 2) + 1)
	{
		while (*position > 0 && *element > 0)
		{
			ft_rotate_double(a, b);
			*element -= 1;
			*position -= 1;
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
			*b = ft_reverse(b, *b, "b", 0);
			position++;
		}
	}
	else
	{
		while (position > 0)
		{
			*b = ft_rotate(b, *b, "b", 0);
			position--;
		}
	}
}

void	move_to_top(t_list **a, int element)
{
	int	lst_size;

	lst_size = ft_lstsize(*a);
	if (element >= (lst_size / 2) + 1)
	{
		while (element < lst_size)
		{
			*a = ft_reverse(a, *a, "a", 0);
			element++;
		}
	}
	else
	{
		while (element > 0)
		{
			*a = ft_rotate(a, *a, "a", 0);
			element--;
		}
	}
}

void	push_chunk_to_b(t_list **a, t_list **b, int *tab)
{
	int		tab_size;
	int		i;
	int		position;
	int		element;

	tab_size = get_tabsize(tab);
	i = 0;
	while (i < tab_size)
	{
		element = find_element_to_push(a, tab);
		if (ft_lstsize(*b) > 1)
		{
			position = find_position(b, change_element_to_node(a, element));
			adjust_lst(a, b, &position, &element);
		}
		move_to_top(a, element);
		if (ft_lstsize(*b) > 1)
			change_order_in_b(b, position);
		*a = ft_push(*a, b, "b");
		i++;
	}
}
