/* ************************************************************************** */
/*                                                                            */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:35:05 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
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

typedef struct s_stack
{
	t_list	*top;
	int		size;
}				t_stack;

/*
** Stack operations
*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*
** Auxiliar and parsing functions
*/
t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_sorted(t_stack *stack);
int		parse_arguments(t_stack *a, int argc, char **argv);
int		check_duplicates(t_stack *stack);
char	*normalize_zero(char *str);
int		is_stack_sorted(t_stack *stack);

/*
** Cluster functions (ya presentes)
*/
void	get_cluster_sizes_recursive(int total_size, int *sizes, int *index);
int		*get_cluster_sizes(int total_size);
void	divide_into_clusters_recursive(t_stack *a, t_stack *b, int *sizes, int index);
void	sort_cluster_recursive(t_stack *b, int cluster_size);
void	sort_all_clusters(t_stack *a, t_stack *b, int *sizes);
int		find_min(t_stack *a);
int		find_position(t_stack *a, int value);
void	sort_cluster_three(t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	final_sweep(t_stack *a);


/*
** Improved algorithm functions (cluster by value)
*/
int		*create_sorted_array(t_stack *a);
void	quicksort(int *arr, int left, int right);
int		*define_boundaries(int *sorted, int total, int chunks);
int		find_position_in_range(t_stack *a, int low, int high);
void	process_cluster(t_stack *a, t_stack *b, int low, int high);
void	process_clusters_by_value(t_stack *a, t_stack *b, int chunks);
int		find_index_in_b(t_stack *b, int val);
void	rotate_a_to_index(t_stack *a, int index);
int		find_target_index(t_stack *a, int val);

/* Reinserción Greedy Optimizada */
int		cost_rotation(int size, int index);
void	perform_optimized_rotations(t_stack *a, t_stack *b, int target_a, int target_b);
int		choose_best_index(t_stack *a, t_stack *b);
int		get_value_at(t_stack *b, int index);
void	greedy_insertion_optimized(t_stack *a, t_stack *b);
void	rotate_b_to_index(t_stack *b, int index);
void	optimized_reinsertion_max(t_stack *a, t_stack *b);






#endif
