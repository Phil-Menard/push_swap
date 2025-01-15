/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/15 18:07:10 by pmenard          ###   ########.fr       */
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

int	get_last_in_tab(int **all_tabs, int index)
{
	int i;
	int	j;
	int	res;

	j = index - 1;
	i = get_tabsize(all_tabs[j]);
	res = all_tabs[j][i - 1];
	return (res);
}

int	*fill_tab(t_list **a, int **tabs, int tab_size, int index)
{
	t_list	*current;
	int		i;

	i = 0;
	while (i < tab_size)
	{
		current = *a;
		tabs[index][i] = 2147483647;
		while (is_in_tab(tabs[index], *(int *)current->content, i) == 0)
			current = current->next;
		while (current != NULL)
		{
			if (*(int *)current->content < tabs[index][i]
				&& is_in_tab(tabs[index], *(int *)current->content, i) == 1)
			{
				if (index == 0
					|| *(int *)current->content > get_last_in_tab(tabs, index))
					tabs[index][i] = *(int *)current->content;
			}
			current = current->next;
		}
		i++;
	}
	return (tabs[index]);
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
