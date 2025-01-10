/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/10 17:59:05 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*push_swap(t_list **a, t_list **b)
{
	int	i;
	int	*tab;
	int	*tabs_size;
	int	chunk_quantity;

	chunk_quantity = find_chunk_quantity(a);
	tabs_size = set_chunk_quantity(a, chunk_quantity);
	i = 0;
	while (chunk_quantity > 1)
	{
		tab = malloc((tabs_size[i] + 1) * sizeof(int));
		tab[tabs_size[i]] = -1;
		tab = fill_tab(a, tab, tabs_size[i]);
		push_chunk_to_b(a, b, tab);
		chunk_quantity--;
		i++;
		free(tab);
	}
	free(tabs_size);
	//sort_a(a);
	sort_b(b);
	while (ft_lstsize(*b) > 0)
		*b = ft_push(*b, a, "b");
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
			a = push_swap(&a, &b);
		print_list(a, "a");
		print_list(b, "b");
		ft_lstclear(&a, &del);
		ft_lstclear(&b, &del);
	}
	return (0);
}
