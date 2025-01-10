/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/10 17:58:00 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//prend un element qui n'est pas dans tab
		tab[i] = -1;
		while (is_in_tab(tab, *(int *)current->content, i) == 0)
			current = current->next;
		tab[i] = *(int *)current->content;
		//trouver + petit element qui n'est pas dans tab
		while (current != NULL)
		{
			if (*(int *)current->content < tab[i]
				&& is_in_tab(tab, *(int *)current->content, i) == 1)
				tab[i] = *(int *)current->content;
			current = current->next;
		}
		i++;
	}
	return (tab);
}

int	get_tabsize(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int	*swap_tab(int *tab, int element)
{
	int	i;
	int	tab_size;

	i = 0;
	while (tab[i] != element)
		i++;
	tab_size = get_tabsize(tab) - 1;
	tab[i] = tab[tab_size];
	tab[tab_size] = -1;
	return (tab);
}
