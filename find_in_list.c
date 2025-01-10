/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:30:56 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/10 13:55:48 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	set_position(t_list **b, t_list *element, int lowest, int bigger)
{
	t_list	*current;
	int		position;

	current = *b;
	position = 0;
	if (*(int *)element->content > bigger)
	{
		while (*(int *)current->content != bigger)
		{
			position++;
			current = current->next;
		}
	}
	else if (*(int *)element->content < lowest)
	{
		while (*(int *)current->content != lowest)
		{
			position++;
			current = current->next;
		}
		position++;
	}
	return (position);
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
	if (*(int *)element->content > bigger || *(int *)element->content < lowest)
		return (set_position(b, element, lowest, bigger));
	while (current->next)
	{
		if (*(int *)element->content < *(int *)current->content
			&& *(int *)element->content > *(int *)current->next->content)
		{
			position++;
			return (position);
		}
		position++;
		current = current->next;
	}
	return (0);
}
