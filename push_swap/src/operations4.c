/* ************************************************************************** */
/*                                                                            */
/*   operations4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_sweep(t_stack *a)
{
	int	min;
	int	pos;

	min = find_min(a);
	pos = find_position(a, min);
	if (pos < 0)
		return ;
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

void	sort_cluster_three(t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = (int)(long)(b->top->content);
	second = (int)(long)(b->top->next->content);
	third = (int)(long)(b->top->next->next->content);
	if (first > second && second < third && third > first)
		sb(b);
	else if (first > second && second > third)
	{
		sb(b);
		rrb(b);
	}
	else if (first > second && second < third && third < first)
		rb(b);
	else if (first < second && second > third && third > first)
	{
		sb(b);
		rb(b);
	}
	else if (first < second && second > third && first > third)
		rrb(b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (!is_sorted(a))
			sa(a);
	}
	else if (a->size == 3)
	{
		if (!is_sorted(a))
			sort_cluster_three(a);
	}
	else if (a->size <= 5)
	{
		while (a->size > 3)
			pb(a, b);
		if (!is_sorted(a))
			sort_cluster_three(a);
		while (b->size > 0)
			pa(a, b);
	}
}

int	find_min(t_stack *a)
{
	t_list	*cur;
	int		min;

	if (!a->top)
		return (0);
	cur = a->top;
	min = (int)(long)(cur->content);
	while (cur)
	{
		if ((int)(long)(cur->content) < min)
			min = (int)(long)(cur->content);
		cur = cur->next;
	}
	return (min);
}

int	find_position(t_stack *a, int value)
{
	t_list	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if ((int)(long)(cur->content) == value)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}
