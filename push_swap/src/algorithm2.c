/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:46:56 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:20:58 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	final_sweep(t_stack *a)
{
	int	pos;

	pos = find_position(a, find_min(a));
	if (pos < 0)
		return ;
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < a->size)
		{
			rra(a);
			pos++;
		}
	}
}
*/
void	sort_all_clusters(t_stack *a, t_stack *b, int *sizes)
{
	int	i;
	int	cluster_size;

	i = 0;
	while (sizes[i] > 0)
	{
		cluster_size = sizes[i];
		while (cluster_size > 0)
		{
			pa(a, b);
			cluster_size--;
		}
		final_sweep(a);
		i++;
	}
}

int	find_min(t_stack *a)
{
	t_list	*current;
	int		min;

	if (!a->top)
		return (0);
	current = a->top;
	min = (int)(long)(current->content);
	while (current)
	{
		if ((int)(long)(current->content) < min)
			min = (int)(long)(current->content);
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *a, int value)
{
	t_list	*current;
	int		position;

	if (!a->top)
		return (-1);
	current = a->top;
	position = 0;
	while (current)
	{
		if ((int)(long)(current->content) == value)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}
