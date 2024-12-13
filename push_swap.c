/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/13 15:02:52 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* void	tri(t_list **a, t_list **b)
{
	print_list(*a, "a");
	print_list(*b, "b");
	*a = ft_swap(*a);
	print_list(*a, "a");
	print_list(*b, "b");
	*a = ft_push(*a, b);
	*a = ft_push(*a, b);
	*a = ft_push(*a, b);
	print_list(*a, "a");
	print_list(*b, "b");
	*a = ft_swap(*a);
	print_list(*a, "a");
	print_list(*b, "b");
	*b = ft_push(*b, a);
	*b = ft_push(*b, a);
	*b = ft_push(*b, a);
	print_list(*a, "a");
	print_list(*b, "b");
} */

void	triotri(t_list **a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (*(int *)third->content < *(int *)second->content 
	&& *(int *)third->content > *(int *)first->content)
	{
		*a = ft_swap(*a, "a");
		*a = ft_rotate(a, *a, "a");
	}
	else if (*(int *)first->content < *(int *)second->content 
	&& *(int *)first->content > *(int *)third->content)
		*a = ft_reverse(a, *a, "a");
	else if (*(int *)first->content > *(int *)second->content 
	&& *(int *)first->content < *(int *)third->content)
		*a = ft_swap(*a, "a");
	else if (*(int *)third->content < *(int *)first->content 
	&& *(int *)third->content > *(int *)second->content)
		*a = ft_rotate(a, *a, "a");
	else if (*(int *)second->content < *(int *)first->content 
	&& *(int *)second->content > *(int *)third->content)
	{
		*a = ft_rotate(a, *a, "a");
		*a = ft_swap(*a, "a");
	}
	print_list(*a, "a");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	//t_list	*b;

	//b = NULL;
	if (argc == 1)
		return (printf("Error\n"), (1));
	else
	{
		if (verify_params(argv) == 1)
			return (printf("Error\n"), (1));
		a = create_list(argv);
		if (a == NULL)
			return (printf("Error\n"), (1));
		triotri(&a);
		ft_lstclear(&a, &del);
		//ft_lstclear(&b, &del);
	}
	return (0);
}
