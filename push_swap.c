/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/08 15:15:26 by pmenard          ###   ########.fr       */
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

int	find_chunk_quantity(t_list **a)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 50)
		return (4);
	else if (size <= 100)
		return (5);
	else if (size <= 200)
		return (6);
	else if (size <= 300)
		return (7);
	else if (size <= 400)
		return (8);
	else if (size <= 450)
		return (9);
	else
		return (10);
}

t_list	*push_swap(t_list **a, t_list **b)
{
	int		*tab;
	int		tab_size;
	int		chunk_quantity;
	int		i;

	tab_size = find_tabsize(a);
	tab = malloc((tab_size + 1) * sizeof(int));
	if (!tab)
		return (NULL);
	tab[tab_size] = -1;
	chunk_quantity = find_chunk_quantity(a);
	i = 1;
	while (i > 0) //2 pour gerer les deux chunks en meme temps?
	{
		tab_size = find_tabsize(a);
		tab = fill_tab(a, tab, tab_size);
		if (chunk_quantity > 2) //ne pas push dernier chunk dans b
			push_chunk_to_b(a, b, tab); //on recupere seulement tableau
		i--;
	}
	free(tab);
	//free(tab); -> ne pas free maintenant, le dernier chumk devrait etre la
	// changer ce qui suit car on a deux chunk dans a!
	//on va push tab dans b, et trier les deux chunks de a et b en meme temps
	//sort_a_and_b
	/* while (ft_lstsize(*b) > 0)
		*b = ft_push(*b, a, "b"); */
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
