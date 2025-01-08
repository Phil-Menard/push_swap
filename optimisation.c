/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:02:23 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/08 15:43:23 by pmenard          ###   ########.fr       */
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
	return (lst_index);
}

int	get_lowest_element(t_list **a, int tabsize, int *nb_instructions)
{
	int	i;
	int	element;
	int	lst_size;
	int	temp_element;
	int	temp_instruction;

	lst_size = ft_lstsize(*a);
	i = -1;
	element = -1;
	while (++i < tabsize)
	{
		if (element == -1)
			element = nb_instructions[i];
		temp_element = element;
		temp_instruction = nb_instructions[i];
		if (temp_element > (lst_size / 2) + 1)
			temp_element = lst_size - temp_element;
		if (nb_instructions[i] > (lst_size / 2) + 1)
			temp_instruction = lst_size - nb_instructions[i];
		if (temp_instruction < temp_element)
			element = nb_instructions[i];
	}
	return (element);
}

int	find_element_to_push(t_list **a, int *tab)
{
	int	i;
	int	element;
	int	tabsize;
	int	*nb_instructions;

	tabsize = get_tabsize(tab);
	nb_instructions = malloc((tabsize + 1) * sizeof(int));
	i = -1;
	while (++i < tabsize)
	{
		ft_printf("tab[i] :      %d\n", tab[i]);
		nb_instructions[i] = get_lstindex(a, tab[i]);
		ft_printf("nb_instructions[i] : %d\n", nb_instructions[i]);
	}
	element = get_lowest_element(a, tabsize, nb_instructions);
	free(nb_instructions);
	return (element);
}