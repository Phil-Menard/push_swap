/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/09 14:29:46 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_int(char *arg)
{
	int		i;
	int		temp;
	char	max[11] = "2147483647";

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (arg[i] == '-')
		max[9] = '8';
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	temp = i;
	while (arg[temp])
		temp++;
	if ((temp - i) > 10)
		return (1);
	else if ((temp - i) < 10)
		return (0);
	else
	{
		temp = 0;
		while (arg[i])
		{
			if (arg[i] > max[temp])
				return (1);
			temp++;
			i++;
		}
		return (0);
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
			if (is_int(argv[i]) == 1)
			{
				printf("Error\n");
				return (0);
			}
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
