/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/16 16:20:14 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sort_three(t_list **a, t_list **b)
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

int	is_in_tab(int *tab, int value, int i)
{
	while (i >= 0)
	{
		if (value == tab[i])
			return (0);
		i--;
	}
	return (1);
}

int	*fill_tab(t_list **a, int *tab, int tab_size)
{
	t_list	*current;
	int		i;

	i = 0;
	while (i < tab_size)
	{
		current = *a;
		tab[i] = -1;
		while (is_in_tab(tab, *(int *)current->content, i) == 0)
			current = current->next;
		tab[i] = *(int *)current->content;
		while (current != NULL)
		{
			if (*(int *)current->content < tab[i]
				&& is_in_tab(tab, *(int *)current->content, i) == 1)
				tab[i] = *(int *)current->content;
			current = current->next;
		}
		ft_printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
	return (tab);
}

t_list	*sort_fourty_max(t_list **a)
{
	int	*tab;
	int	tab_size;

	if (ft_lstsize(*a) % 2 == 0)
		tab_size = ft_lstsize(*a) / 2;
	else
		tab_size = (ft_lstsize(*a) / 2) + 1;
	tab = malloc((tab_size + 1) * sizeof(int));
	if (!tab)
		return (NULL);
	tab[tab_size] = -1;
	tab = fill_tab(a, tab, tab_size);
	free(tab);
	return (*a);
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
			a = sort_fourty_max(&a);
		print_list(a, "a");
		ft_lstclear(&a, &del);
		ft_lstclear(&b, &del);
	}
	return (0);
}
