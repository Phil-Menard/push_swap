/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:06 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/13 11:56:43 by pmenard          ###   ########.fr       */
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

void	del(void *content)
{
	free(content);
}

char	**handle_args(int argc, char **argv)
{
	char	**arg;
	int		i;
	int		j;

	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		while (argv[i])
			i++;
		arg = malloc(i * sizeof(char *));
		i = 1;
		j = 0;
		while (argv[i])
		{
			arg[j] = ft_strdup(argv[i]);
			j++;
			i++;
		}
	}
	return (arg);
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
	*content = ft_atoi(argv[0]);
	lst = ft_lstnew((void *)content);
	i = 1;
	while (argv[i])
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = ft_atoi(argv[i]);
		new = ft_lstnew((void *)content);
		if (check_doubles(&lst, new))
			ft_lstadd_back(&lst, new);
		else
			return (ft_lstclear(&new, &del), ft_lstclear(&lst, &del), NULL);
		i++;
	}
	return (lst);
}
