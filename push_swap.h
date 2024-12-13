/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:20 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/13 11:04:28 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	print_list(t_list *lst, const char *lstname);
t_list	*create_list(char **argv);
t_list	*ft_swap(t_list *lst);
t_list	*ft_push(t_list *a, t_list **b);
t_list	*ft_rotate(t_list **lst, t_list *a);
t_list	*ft_reverse(t_list **lst, t_list *node);
void	del(void *content);

#endif