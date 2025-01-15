/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:54:20 by pmenard           #+#    #+#             */
/*   Updated: 2025/01/15 17:27:26 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	print_list(t_list *lst, const char *lstname);
char	**handle_args(int argc, char **argv);
t_list	*create_list(char **argv);
t_list	*ft_swap(t_list *lst, const char *lstname);
t_list	*ft_push(t_list *a, t_list **b, const char *lstname);
t_list	*ft_rotate(t_list **lst, t_list *a, const char *lstname, int x);
t_list	*ft_reverse(t_list **lst, t_list *node, const char *lstname, int x);
void	ft_rotate_double(t_list **a, t_list **b);
void	ft_reverse_double(t_list **a, t_list **b);
int		find_chunk_quantity(t_list **a);
int		*set_chunk_quantity(t_list **a, int chunk_quantity);
int		get_tabsize(int *tab);
int		*swap_tab(int *tab, int element);
int		get_lstindex(t_list **a, int index_tab);
int		*fill_tab(t_list **a, int **tabs, int tab_size, int index);
void	push_chunk_to_b(t_list **a, t_list **b, int *tab);
int		find_element_to_push(t_list **a, int *tab);
int		find_position(t_list **b, t_list *element);
int		get_smallest_element(t_list **b);
int		get_bigger_element(t_list **b);
t_list	*change_element_to_node(t_list **a, int element);
void	sort_a(t_list **a);
void	sort_b(t_list **b);
void	change_order_in_b(t_list **b, int position);
int		verify_params(char **argv);
int		check_doubles(t_list **lst, t_list *node);
void	del(void *content);
void	free_arg(char **arg);

#endif