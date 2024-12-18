/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:20 by pmenard           #+#    #+#             */
/*   Updated: 2024/12/18 15:18:42 by pmenard          ###   ########.fr       */
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
t_list	*ft_swap(t_list *lst, const char *lstname);
t_list	*ft_push(t_list *a, t_list **b, const char *lstname);
t_list	*ft_rotate(t_list **lst, t_list *a, const char *lstname);
t_list	*ft_reverse(t_list **lst, t_list *node, const char *lstname);
int		get_tabsize(t_list **a);
int		*fill_tab(t_list **a, int *tab, int tab_size);
void	from_tab_tb(t_list **a, t_list **b, int *tab);
void	find_best_way(int *tab_count, t_list **a, t_list **b);
int		count_instructions(int lst_index, t_list **a);
int		verify_params(char **argv);
void	del(void *content);

#endif