/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:47:52 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/18 16:01:12 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lower(int *tab_count)
{
	int	i;
	int	res;
	int	min;

	i = 0;
	res = 0;
	min = 2147483646;
	while (tab_count[i] != -1)
	{
		if (min > tab_count[i] && tab_count[i] != -2)
		{
			min = tab_count[i];
			res = i;
		}
		i++;
	}
	tab_count[i] = -2;
	ft_printf("res : %d\n", res);
	return (res);
}

void	find_best_way(int *tab_count, t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		tab_size;

	tab_size = get_tabsize(a);
	j = 0;
	while (j < tab_size)
	{
		i = get_lower(tab_count);
		while
		if (i <= tab_size)
		{
			ft_printf("aqui\n");
			while (i > 0)
			{
				*a = ft_rotate(a, *a, "a");
				i--;
			}
		}
		else
		{
			ft_printf("there\n");
			while (i < ft_lstsize(*a))
			{
				*a = ft_rotate(a, *a, "a");
				i--;
			}
		}
		*a = ft_push(*a, b, "b");
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
