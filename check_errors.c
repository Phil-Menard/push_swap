/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:03:06 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/13 14:49:00 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_params(char **argv)
{
	int		i;
	int		value;
	char	*content;

	i = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		content = ft_itoa(value);
		if (ft_strncmp(argv[i], content, ft_strlen(argv[i])) != 0)
			return (free(content), (0));
		free(content);
		i++;
	}
	return (1);
}

int	check_doubles(t_list **lst, t_list *node)
{
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		if (*(int *)node->content == *(int *)current->content)
			return (0);
		current = current->next;
	}
	return (1);
}
