/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:58:24 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:19:36 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	tmp = (int)(long)(first->content);
	first->content = second->content;
	second->content = (void *)(long)tmp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	b->size--;
	ft_lstadd_front(&(a->top), tmp);
	a->size++;
	ft_printf("pa\n");
}


