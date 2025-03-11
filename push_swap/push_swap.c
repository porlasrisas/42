/* ************************************************************************** */
/*                                                                            */
/*   push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	calc_cost(t_stack *a, t_stack *b, int candidate, int idx)
{
	int	target = find_target_index(a, candidate);
	return (cost_rotation(b->size, idx) + cost_rotation(a->size, target));
}

int	choose_best_index(t_stack *a, t_stack *b)
{
	t_list	*cur;
	int		idx, best_idx, best_cost, cost;

	if (b->size == 0) return (0);
	cur = b->top;
	idx = best_idx = 0; best_cost = INT_MAX;
	while (cur)
	{
		cost = calc_cost(a, b, (int)(long)(cur->content), idx);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_idx = idx;
		}
		idx++;
		cur = cur->next;
	}
	return (best_idx);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!parse_arguments(a, argc, argv) || !check_duplicates(a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (a->size <= 5)
		sort_small(a, b);
	else if (a->size <= 100)
	{
		process_clusters_by_value(a, b, 2);
		greedy_insertion_optimized(a, b);
	}
	else
	{
		process_clusters_by_value(a, b, 4);
		greedy_insertion_optimized(a, b);
	}
	return (0);
}
