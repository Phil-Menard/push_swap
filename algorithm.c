/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:24:44 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/09 17:18:20 by pmenard          ###   ########.fr       */
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

int	get_bigger_element(t_list **b)
{
	t_list	*current;
	int		content;

	current = *b;
	content = *(int *)current->content;
	while (current->next)
	{
		if (*(int *)current->content > content)
			content = *(int *)current->content;
		current = current->next;
	}
	return (content);
}

int	get_smallest_element(t_list **b)
{
	t_list	*current;
	int		content;

	current = *b;
	content = *(int *)current->content;
	while (current->next)
	{
		if (*(int *)current->content < content)
			content = *(int *)current->content;
		current = current->next;
	}
	return (content);
}

int	find_position(t_list **b, t_list *element)
{
	t_list	*current;
	int		position;
	int		bigger;
	int		lowest;

	current = *b;
	position = 0;
	bigger = get_bigger_element(b);
	lowest = get_smallest_element(b);
	if (*(int *)element->content > bigger)
	{
		while (*(int *)current->content != bigger)
		{
			position++;
			current = current->next;
		}
		return (position);
	}
	else if (*(int *)element->content < lowest)
	{
		while (*(int *)current->content != lowest)
		{
			position++;
			current = current->next;
		}
		position++;
		return (position);
	}
	else
	{
		while (current->next)
		{
			if (*(int *)element->content < *(int *)current->content)
			{
				if (*(int *)element->content > *(int *)current->next->content)
				{
					position++;
					return (position);
				}
			}
			position++;
			current = current->next;
		}
	}
	return (0);
}

void	sort_b(t_list **b, t_list **a)
{
	int	position;

	position = find_position(b, *a);
	while (position > 0)
	{
		*b = ft_rotate(b, *b, "b");
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
		print_list(*b, "b");
		if (ft_lstsize(*b) > 1)
			sort_b(b, a);
		*a = ft_push(*a, b, "a");
		i++;
	}
}
