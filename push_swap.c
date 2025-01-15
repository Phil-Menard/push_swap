/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/15 18:19:54 by pmenard          ###   ########.fr       */
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

int	**fill_all_tab(t_list **a, int **all_tabs, int *tabs_size, int chunk_qty)
{
	int	i;
	int	j;

	i = 0;
	while (i < chunk_qty)
	{
		j = 0;
		all_tabs[i] = malloc((tabs_size[i] + 1) * sizeof(int));
		all_tabs[i][tabs_size[i]] = -1;
		all_tabs[i] = fill_tab(a, all_tabs, tabs_size[i], i);
		while (all_tabs[i][j] != -1)
		{
			ft_printf("all_tabs[%d][%d] :%d\n", i, j, all_tabs[i][j]);
			j++;
		}
		i++;
	}
	return (all_tabs);
}

int	compare_totals(int *totals)
{
	int	i;
	int	temp;
	int	res;
	int	tab_size;

	i = 0;
	temp = 2147483647;
	tab_size = get_tabsize(totals);
	while (i < tab_size)
	{
		if (totals[i] < temp)
		{
			temp = totals[i];
			res = i;
		}
		i++;
	}
	return (res);
}

int	find_best_chunk(t_list **a, int **all_tabs, int chunk_quantity)
{
	int	i;
	int	j;
	int	best_chunk;
	int	tab_size;
	int	*totals;

	i = -1;
	totals = malloc((chunk_quantity + 1) * sizeof(int));
	while (++i < chunk_quantity)
	{
		totals[i] = 0;
		ft_printf("i : %d\n", i);
		tab_size = get_tabsize(all_tabs[i]);
		if (all_tabs[i][1] == -1)
			totals[i] = 100000000;
		else
		{
			j = -1;
			while (++j < tab_size)
				totals[i] += get_lstindex(a, all_tabs[i][j]);
		}
	}
	totals[i] = -1;
	best_chunk = compare_totals(totals);
	free(totals);
	return (best_chunk);
}

void	push_swap(t_list **a, t_list **b)
{
	int	i;
	int	chunk_quantity;
	int	*tabs_size;
	int	tab_best_chunk;
	int	**all_tabs;

	chunk_quantity = find_chunk_quantity(a);
	tabs_size = set_chunk_quantity(a, chunk_quantity);
	all_tabs = malloc((chunk_quantity + 1) * sizeof(int *));
	all_tabs[chunk_quantity] = NULL;
	all_tabs = fill_all_tab(a, all_tabs, tabs_size, chunk_quantity);
	i = 0;
	while (chunk_quantity > 0)
	{
		tab_best_chunk = find_best_chunk(a, all_tabs, chunk_quantity);
		push_chunk_to_b(a, b, all_tabs[tab_best_chunk]);
		all_tabs[tab_best_chunk][1] = -1;
		chunk_quantity--;
		i++;
	}
	free(tabs_size);
	free(all_tabs);
	if (!is_sorted(a))
		sort_a(a);
	if (ft_lstsize(*b) > 1)
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
		return (1);
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
