/* ************************************************************************** */
/*                                                                            */
/*   optimized_reinsertion_max.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

int	find_max_opt(t_stack *s)
{
	t_list	*cur;
	int		max;

	if (!s->top)
		return (INT_MIN);
	cur = s->top;
	max = (int)(long)(cur->content);
	while (cur)
	{
		if ((int)(long)(cur->content) > max)
			max = (int)(long)(cur->content);
		cur = cur->next;
	}
	return (max);
}

int	find_index_in_b_opt(t_stack *b, int val)
{
	t_list	*cur;
	int		index;

	cur = b->top;
	index = 0;
	while (cur)
	{
		if ((int)(long)(cur->content) == val)
			return (index);
		index++;
		cur = cur->next;
	}
	return (-1);
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

static void	combined_rotations_opt(t_stack *a, t_stack *b, int *target_a, int *target_b)
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

void	optimized_reinsertion_max(t_stack *a, t_stack *b)
{
	int	max;
	int	index_b;
	int	target_a;

	while (b->size > 0)
	{
		max = find_max_opt(b);
		index_b = find_index_in_b_opt(b, max);
		if (a->size == 0)
			target_a = 0;
		else
		{
			int	current_max = find_max_opt(a);
			target_a = (find_position(a, current_max) + 1) % a->size;
		}
		combined_rotations_opt(a, b, &target_a, &index_b);
		rotate_b_to_index(b, index_b);
		rotate_a_to_index(a, target_a);
		pa(a, b);
	}
	final_sweep(a);
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