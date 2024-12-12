/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:08:10 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/12 16:21:16 by pmenard          ###   ########.fr       */
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
