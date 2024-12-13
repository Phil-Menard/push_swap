/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/13 17:34:08 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_list **a)
{
	t_list	*current;

	current = *a;
	while (current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_list **a, t_list **b)
{
	t_list	*a_first;

	*a = ft_push(*a, b, "b");
	a_first = *a;
	if (*(int *)a_first->content > *(int *)a_first->next->content)
		*a = ft_swap(*a, "a");
	*b = ft_push(*b, a, "a");
	a_first = *a;
	if (*(int *)a_first->content > *(int *)a_first->next->content)
	{
		if (*(int *)a_first->content > *(int *)a_first->next->next->content)
			*a = ft_rotate(a, *a, "a");
		else
			*a = ft_swap(*a, "a");
	}
}

void	sort_four(t_list **a, t_list **b)
{
	t_list	*a_first;
	t_list	*a_last;

	*a = ft_push(*a, b, "b");
	sort_three(a, b);
	*b = ft_push(*b, a, "b");
	a_last = *a;
	while (a_last->next != NULL)
		a_last = a_last->next;
	a_first = *a;
	if (*(int *)a_first->content > *(int *)a_first->next->content)
	{
		*a = ft_swap(*a, "a");
		sort_four(a, b);
	}
	else if (*(int *)a_first->content > *(int *)a_last->content)
		*a = ft_rotate(a, *a, "a");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc == 1)
		return (ft_printf("Error\n"), (1));
	else
	{
		if (!verify_params(argv))
			return (ft_printf("Error\n"), (1));
		a = create_list(argv);
		if (a == NULL)
			return (ft_printf("Error\n"), (1));
		if (!is_sorted(&a))
			sort_four(&a, &b);
		print_list(a, "a");
		ft_lstclear(&a, &del);
		ft_lstclear(&b, &del);
	}
	return (0);
}
