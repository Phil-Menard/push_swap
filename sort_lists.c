/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:58:11 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/14 17:19:46 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_a(t_list **a)
{
	t_list	*first;
	t_list	*second;

	first = *a;
	second = first->next;
	if (*(int *)first->content == get_smallest_element(a))
	{
		*a = ft_swap(*a, "a");
		*a = ft_rotate(a, *a, "a", 0);
	}
	else if (*(int *)first->content != get_smallest_element(a)
		&& *(int *)first->content != get_bigger_element(a))
	{
		if (*(int *)first->content > *(int *)second->content)
			*a = ft_swap(*a, "a");
		else
			*a = ft_reverse(a, *a, "a", 0);
	}
	else if (*(int *)first->content == get_bigger_element(a))
	{
		*a = ft_rotate(a, *a, "a", 0);
		if (*(int *)second->content != get_smallest_element(a))
			*a = ft_swap(*a, "a");
	}
}
