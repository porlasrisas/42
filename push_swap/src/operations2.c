/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:24:51 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:07 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_printf("rr\n");
}

static void	reverse_rotate_stack(t_stack *stack)
{
	t_list	*last;
	t_list	*second_last;

	if (stack->size < 2)
		return ;
	second_last = stack->top;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr\n");
}
