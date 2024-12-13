/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:08:10 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/13 11:08:11 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list *lst)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	first = lst;
	second = lst->next;
	first->next = second->next;
	second->next = first;
	return (second);
}

t_list	*ft_push(t_list *a, t_list **b)
{
	t_list	*second;

	if (a == NULL || b == NULL)
		return (NULL);
	second = a->next;
	ft_lstadd_front(b, a);
	return (second);
}

t_list	*ft_rotate(t_list **lst, t_list *node)
{
	t_list	*second;

	if (node == NULL)
		return (NULL);
	second = node->next;
	ft_lstadd_back(lst, node);
	node->next = NULL;
	return (second);
}

t_list	*ft_reverse(t_list **lst, t_list *node)
{
	t_list	*last;

	if (node == NULL)
		return (NULL);
	last = node->next;
	while (last->next != NULL)
		last = last->next;
	while (node->next != last)
		node = node->next;
	node->next = NULL;
	ft_lstadd_front(lst, last);
	return (last);
}
