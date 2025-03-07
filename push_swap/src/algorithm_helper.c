/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:21:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

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
	else if (first < second && second > third && third < first)
		rrb(b);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	a->size--;
	ft_lstadd_front(&(b->top), tmp);
	b->size++;
	ft_printf("pb\n");
}
