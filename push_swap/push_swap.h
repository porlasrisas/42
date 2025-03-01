/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:35:05 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:23:03 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

/*
** Stack operations
*/
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*
** Auxiliar and parsing functions
*/
t_stack				*init_stack(void);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
int					is_sorted(t_stack *stack);
void				print_stack(t_stack *stack);

int					parse_arguments(t_stack *a, int argc, char **argv);
int					check_duplicates(t_stack *stack);
int					split_and_store(int argc, char **argv, char **all_args);
char				*normalize_zero(char *str);
int					convert_and_store(char **all_args, int k, char *num_str);
int					is_stack_sorted(t_stack *a);
void				get_cluster_sizes_recursive(int total_size, int *sizes,
						int *index);
int					*get_cluster_sizes(int total_size);
void				divide_into_clusters_recursive(t_stack *a, t_stack *b,
						int *sizes, int index);
void				sort_cluster_recursive(t_stack *b, int cluster_size);
void				final_sweep(t_stack *a);
void				sort_all_clusters(t_stack *a, t_stack *b, int *sizes);
int					find_min(t_stack *a);
int	                find_position(t_stack *a, int value);

#endif
