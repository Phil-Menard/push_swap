/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/09 12:12:31 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("content : %d\n", lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstnew(int n)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = n;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*new;
	int		i;

	if (argc == 1)
	{
		printf("Error\n");
		return (0);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			printf("%d\n", atoi(argv[i]));
			/* if (atoi(argv[i]) == INT_MIN || atoi(argv[i]) == INT_MAX)
			{
				printf("Error\n");
				return (0);
			} */
			printf("ok\n");
			i++;
		}
		lst = ft_lstnew(atoi(argv[1]));
		i = 2;
		while (argv[i])
		{
			new = ft_lstnew(atoi(argv[i]));
			ft_lstadd_back(&lst, new);
			i++;
		}
		print_list(lst);
	}
	return (0);
}
