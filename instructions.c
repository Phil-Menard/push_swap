/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:08:10 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/13 15:34:10 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_swap(t_list *lst, const char *lstname)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	first = lst;
	second = lst->next;
	first->next = second->next;
	second->next = first;
	ft_printf("s%s\n", lstname);
	return (second);
}

t_list	*ft_push(t_list *a, t_list **b, const char *lstname)
{
	t_list	*second;

	if (a == NULL || b == NULL)
		return (NULL);
	second = a->next;
	ft_lstadd_front(b, a);
	ft_printf("p%s\n", lstname);
	return (second);
}

t_list	*ft_rotate(t_list **lst, t_list *node, const char *lstname, int x)
{
	t_list	*second;

	if (node == NULL)
		return (NULL);
	second = node->next;
	ft_lstadd_back(lst, node);
	node->next = NULL;
	if (x == 0)
		ft_printf("r%s\n", lstname);
	else
		ft_printf("r");
	return (second);
}

t_list	*ft_reverse(t_list **lst, t_list *node, const char *lstname, int x)
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
	if (x == 0)
		ft_printf("rr%s\n", lstname);
	else
		ft_printf("r");
	return (last);
}
