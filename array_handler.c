/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:39:36 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/19 15:42:57 by pmenard          ###   ########.fr       */
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
		i++;
	}
	return (tab);
}

int	get_tabsize(t_list **a)
{
	int		tab_size;

	if (ft_lstsize(*a) % 2 == 0)
		tab_size = ft_lstsize(*a) / 2;
	else
		tab_size = (ft_lstsize(*a) / 2) + 1;
	return (tab_size);
}

void	from_tab_tb(t_list **a, t_list **b, int *tab)
{
	t_list	*current;
	int		i;
	int		lst_index;
	int		tab_size;
	int		*tab_count;

	i = 0;
	tab_size = get_tabsize(a);
	tab_count = malloc((tab_size + 1) * sizeof(int));
	while (i < tab_size)
	{
		current = *a;
		lst_index = 0;
		while (*(int *)current->content != tab[i])
		{
			current = current->next;
			lst_index++;
		}
		tab_count[i] = count_instructions(lst_index, a);
		i++;
	}
	algo(tab_count, tab, a, b);
	free(tab_count);
}
