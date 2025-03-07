/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 20:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_stack *a)
{
	if (!is_stack_sorted(a))
		sa(a);
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = (int)(long)(a->top->content);
	second = (int)(long)(a->top->next->content);
	third = (int)(long)(a->top->next->next->content);
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 3)
	{
		min = find_min(a);
		pos = find_position(a, min);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
