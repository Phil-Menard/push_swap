/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:05:20 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/18 11:35:56 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/* 
void	del(void *content)
{
	free(content);
} */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	while (current != NULL)
	{
		temp = current->next;
		if (current->content)
			del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}

/* 	[temp]
			[curr]
			[node1]	[adel]	[node3] */
/*#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		*a;
	int		*b;
	int		*c;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 20;
	*b = 30;
	*c = 40;
	node1 = ft_lstnew(a);
	node2 = ft_lstnew(b);
	node3 = ft_lstnew(c);
	node1->next = node2;
	node2->next = node3;
	printf("adresse noeud 1 : %p\n", node1);
	printf("adresse noeud 2 : %p\n", node2);
	printf("adresse noeud 3 : %p\n", node3);
	printf("--------------------\n");
	ft_lstclear(&node1, &del);
	if (node1 == NULL)
		printf("content deleted\n");
	else
		printf("adresse noeud 1 : %p\n", node1);
	if (node2 == NULL)
		printf("content deleted\n");
	else
		printf("adresse noeud 2 : %p\n", node2);
	if (node3 == NULL)
		printf("content deleted\n");
	else
		printf("adresse noeud 3 : %p\n", node3);
	return (0);
} 
*/