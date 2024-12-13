/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:06 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/13 11:51:08 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *lst, const char *lstname)
{
	ft_printf("%s : ", lstname);
	while (lst != NULL)
	{
		ft_printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	verify_params(char **argv)
{
	int		i;
	int		value;
	char	*content;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		content = ft_itoa(value);
		if (ft_strncmp(argv[i], content, ft_strlen(argv[i])) != 0)
			return (free(content), (1));
		free(content);
		i++;
	}
	return (0);
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
