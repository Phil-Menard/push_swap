/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:47:52 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/19 17:11:24 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lower_elements(int *tab_count, int tab_size)
{
	int	i;
	int	res;
	int	min;

	res = 0;
	i = 0;
	min = 2147483646;
	while (i < tab_size)
	{
		if (min > tab_count[i] && tab_count[i] != -2)
		{
			min = tab_count[i];
			res = i;
		}
		i++;
	}
	tab_count[res] = -2;
	return (res);
}

int	get_index_lower_element(int *tab_count, int tab_size, int *tab, t_list **a)
{
	t_list	*current;
	int		index;
	int		i;

	i = 0;
	current = *a;
	index = get_lower_elements(tab_count, tab_size);
	while (*(int *)current->content != tab[index])
	{
		current = current->next;
		i++;
	}
	tab[index] = -2;
	return (i);
}

void	sort_b(t_list **b)
{
	t_list	*current;
	t_list	*first;
	int		i;
	int		temp;

	first = *b;
	current = first->next;
	i = 0;
	while (current 
		&& *(int *)first->content < *(int *)current->content)
	{
		current = current->next;
		i++;
	}
	if (i < get_tabsize(b))
	{
		temp = i;
		while (i > 0)
		{
			*b = ft_swap(*b, "b");
			if (i != 1)
				*b = ft_rotate(b, *b, "b");
			i--;
		}
		i++;
		while (i < temp)
		{
			*b = ft_reverse(b, *b, "b");
			i++;
		}
	}
	else
	{
		temp = i;
		while (i < ft_lstsize(*b))
		{
			*b = ft_reverse(b, *b, "b");
			*b = ft_swap(*b, "b");
			i++;
		}
		i--;
		while (i > temp)
		{
			*b = ft_rotate(b, *b, "b");
			i--;
		}
	}
	print_list(*b, "b");
}

void	algo(int *tab_count, int *tab, t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		tab_size;

	tab_size = get_tabsize(a);
	j = 0;
	while (j < tab_size)
	{
		i = get_index_lower_element(tab_count, tab_size, tab, a);
		if (i <= tab_size)
		{
			while (i-- > 0)
				*a = ft_rotate(a, *a, "a");
		}
		else
		{
			while (i++ < ft_lstsize(*a))
				*a = ft_reverse(a, *a, "a");
		}
		*a = ft_push(*a, b, "b");
		if (ft_lstsize(*b) > 1)
			sort_b(b);
		j++;
	}
}

int	count_instructions(int lst_index, t_list **a)
{
	int	i;

	i = 0;
	if (lst_index <= get_tabsize(a))
	{
		while (lst_index > 0)
		{
			lst_index--;
			i++;
		}
		return (i);
	}
	else
	{
		while (lst_index < ft_lstsize(*a))
		{
			i++;
			lst_index++;
		}
		return (i);
	}
}
