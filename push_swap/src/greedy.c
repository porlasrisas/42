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


int	get_value_at(t_stack *b, int index)
{
	t_list	*cur;
	int		value;

	cur = b->top;
	while (index-- > 0 && cur)
		cur = cur->next;
	if (cur)
		value = (int)(long)(cur->content);
	else
		value = 0;
	return (value);
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
