/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/14 14:10:39 by pmenard          ###   ########.fr       */
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

void	push_swap(t_list **a, t_list **b)
{
	int	i;
	int	*tab;
	int	*tabs_size;
	int	chunk_quantity;

	chunk_quantity = find_chunk_quantity(a);
	tabs_size = set_chunk_quantity(a, chunk_quantity);
	i = 0;
	while (chunk_quantity > 0)
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
	if (!is_sorted(a))
		sort_a(a);
	sort_b(b);
	while (ft_lstsize(*b) > 0)
		*b = ft_push(*b, a, "a");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**arg;

	b = NULL;
	if (argc == 1)
		return (ft_printf("Error\n"), (1));
	else
	{
		arg = handle_args(argc, argv);
		if (!verify_params(arg))
			return (free_arg(arg), ft_printf("Error\n"), (1));
		a = create_list(arg);
		if (a == NULL)
			return (free_arg(arg), ft_printf("Error\n"), (1));
		free_arg(arg);
		if (!is_sorted(&a))
			push_swap(&a, &b);
		ft_lstclear(&a, &del);
		ft_lstclear(&b, &del);
	}
	return (0);
}
