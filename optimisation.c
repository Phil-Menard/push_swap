/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:02:23 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/06 17:06:45 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lstindex(t_list **a, int index_tab)
{
	int		lst_index;
	int		lst_size;
	t_list	*current;

	lst_index = 0;
	current = *a;
	lst_size = ft_lstsize(*a);
	while (*(int *)current->content != index_tab)
	{
		current = current->next;
		lst_index++;
	}
	if (lst_index > ((lst_size / 2) + 1))
		return (lst_size - lst_index);
	return (lst_index);
}

int	*optimise_tab(t_list **a, int *tab)
{
	int	i;
	int	tabsize;
	int	*nb_count;

	tabsize = get_tabsize(a);
	nb_count = malloc((tabsize + 1) * sizeof(int));
	i = -1;
	while (++i < tabsize)
	{
		ft_printf("tab[i] :      %d\n", tab[i]);
		nb_count[i] = get_lstindex(a, tab[i]);
		ft_printf("nb_count[i] : %d\n", nb_count[i]);
	}
	/* i = 0;
	while (i < tabsize)
	{

		i++;
	} */
	free(nb_count);
	return (tab);
}
