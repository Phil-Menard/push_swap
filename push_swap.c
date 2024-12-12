/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:00 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/12 16:20:37 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc == 1)
		return (printf("Error\n"), (1));
	else
	{
		if (verify_params(argv) == 1)
			return (printf("Error\n"), (1));
		a = create_list(argv);
		if (a == NULL)
			return (printf("Error\n"), (1));
		print_list(a);
		/* a = ft_swap(a);
		printf("\n");
		print_list(a); */
		a = ft_push(a, &b);
		printf("a : \n");
		print_list(a);
		printf("b : \n");
		print_list(b);
		ft_lstclear(&a, &del);
		ft_lstclear(&b, &del);
	}
	return (0);
}
