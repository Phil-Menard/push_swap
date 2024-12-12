/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:06 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/12 15:21:15 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	check_doubles(t_list **lst, t_list *node)
{
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		if (*(int *)node->content == *(int *)current->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	del(void *content)
{
	free(content);
}

t_list	*create_list(char **argv)
{
	t_list	*lst;
	t_list	*new;
	int		*content;
	int		i;

	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = ft_atoi(argv[1]);
	lst = ft_lstnew((void *)content);
	i = 2;
	while (argv[i])
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		new = ft_lstnew((void *)content);
		if (check_doubles(&lst, new) == 0)
			ft_lstadd_back(&lst, new);
		else
			return (ft_lstclear(&new, &del), ft_lstclear(&lst, &del), NULL);
		i++;
	}
	return (lst);
}
