/* ************************************************************************** */
/*                                                                            */
/*   greedy_insertion_optimized.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_max(t_stack *a)
{
	t_list	*cur;
	int		max;

	if (!a->top)
		return (INT_MIN);
	cur = a->top;
	max = (int)(long)(cur->content);
	while (cur)
	{
		if ((int)(long)(cur->content) > max)
			max = (int)(long)(cur->content);
		cur = cur->next;
	}
	return (max);
}

int	cost_rotation(int size, int index)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}

static void	combined_rotations(t_stack *a, t_stack *b, int *target_a, int *target_b)
{
	while (*target_a > 0 && *target_b > 0 &&
		(*target_a <= a->size / 2) && (*target_b <= b->size / 2))
	{
		rr(a, b);
		(*target_a)--;
		(*target_b)--;
	}
	while (*target_a > 0 && *target_b > 0 &&
		(*target_a > a->size / 2) && (*target_b > b->size / 2))
	{
		rrr(a, b);
		*target_a = *target_a + 1;
		*target_b = *target_b + 1;
	}
}

int	choose_best_index(t_stack *a, t_stack *b)
{
	t_list	*cur;
	int		index;
	int		best_index;
	int		best_cost;
	int		candidate;
	int		target;
	int		total_cost;

	if (b->size == 0)
		return (0);
	cur = b->top;
	index = 0;
	best_index = 0;
	best_cost = INT_MAX;
	while (cur)
	{
		candidate = (int)(long)(cur->content);
		target = find_target_index(a, candidate);
		total_cost = cost_rotation(b->size, index) + cost_rotation(a->size, target);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			best_index = index;
		}
		index++;
		cur = cur->next;
	}
	return (best_index);
}

int	get_value_at(t_stack *b, int index)
{
	t_list	*cur;

	cur = b->top;
	while (index-- > 0 && cur)
		cur = cur->next;
	return (cur ? (int)(long)(cur->content) : 0);
}

int	find_target_index(t_stack *a, int val)
{
	int		min;
	int		max;
	int		index;
	t_list	*cur;

	if (a->size == 0)
		return (0);
	min = find_min(a);
	max = find_max(a);
	if (val < min || val > max)
		return ((find_position(a, max) + 1) % a->size);
	index = 0;
	cur = a->top;
	while (cur && cur->next)
	{
		if ((int)(long)(cur->content) <= val &&
			val <= (int)(long)(cur->next->content))
			return (index + 1);
		index++;
		cur = cur->next;
	}
	return (0);
}

void	greedy_insertion_optimized(t_stack *a, t_stack *b)
{
	int	best;
	int	candidate;
	int	target_a;
	int	target_b;

	while (b->size > 0)
	{
		best = choose_best_index(a, b);
		rotate_b_to_index(b, best);
		candidate = get_value_at(b, 0);
		target_a = find_target_index(a, candidate);
		target_b = 0;
		combined_rotations(a, b, &target_a, &target_b);
		rotate_a_to_index(a, target_a);
		rotate_b_to_index(b, target_b);
		pa(a, b);
	}
	final_sweep(a);
}
void	rotate_a_to_index(t_stack *a, int index)
{
	int	r;

	if (index <= a->size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		r = a->size - index;
		while (r-- > 0)
			rra(a);
	}
}
void	rotate_b_to_index(t_stack *b, int index)
{
	int	r;

	if (index <= b->size / 2)
	{
		while (index-- > 0)
			rb(b);
	}
	else
	{
		r = b->size - index;
		while (r-- > 0)
			rrb(b);
	}
}