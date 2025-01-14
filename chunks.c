/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:58:45 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/15 16:08:51 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_chunk_quantity(t_list **a)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 20)
		return (2);
	else if (size <= 50)
		return (4);
	else if (size <= 100)
		return (6);
	else if (size <= 200)
		return (7);
	else if (size <= 300)
		return (8);
	else if (size <= 400)
		return (10);
	else if (size <= 450)
		return (12);
	else
		return (13);
}

int	*remove_last_three(int *tabs_size, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size;
	while (i < 3)
	{
		if (size < 0)
			size = j;
		tabs_size[size] -= 1;
		size--;
		i++;
	}
	return (tabs_size);
}

int	*set_chunk_quantity(t_list **a, int chunk_quantity)
{
	int	*tabs_size;
	int	chunk_size;
	int	remainder;
	int	lst_size;
	int	i;

	tabs_size = malloc((chunk_quantity + 1) * sizeof(int));
	tabs_size[chunk_quantity] = -1;
	lst_size = ft_lstsize(*a);
	chunk_size = lst_size / chunk_quantity;
	remainder = lst_size % chunk_quantity;
	i = -1;
	while (++i < chunk_quantity)
	{
		tabs_size[i] = chunk_size;
		if (remainder > 0)
		{
			tabs_size[i] += 1;
			remainder--;
		}
	}
	tabs_size = remove_last_three(tabs_size, (chunk_quantity - 1));
	return (tabs_size);
}
