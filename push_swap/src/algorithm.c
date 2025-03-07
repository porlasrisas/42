/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:24:09 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:20:38 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_stack *a)
{
	t_list	*current;

	if (!a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next)
	{
		if ((int)(long)(current->content) > (int)(long)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

void	get_cluster_sizes_recursive(int total_size, int *sizes, int *index)
{
	int	size1;
	int	size2;

	if (total_size <= 5)
	{
		sizes[*index] = total_size;
		(*index)++;
		return ;
	}
	if (total_size % 2 == 0)
	{
		size1 = total_size * 60 / 100;
		size2 = total_size - size1;
	}
	else
	{
		size1 = total_size / 2 + 1;
		size2 = total_size / 2;
	}
	sizes[*index] = size1;
	(*index)++;
	get_cluster_sizes_recursive(size2, sizes, index);
}

int	*get_cluster_sizes(int total_size)
{
	int	*sizes;
	int	index;

	sizes = malloc(total_size + 1 * sizeof(int));
	if (!sizes)
		return (NULL);
	index = 0;
	get_cluster_sizes_recursive(total_size, sizes, &index);
	sizes[index] = 0;
	return (sizes);
}

void	divide_into_clusters_recursive(t_stack *a, t_stack *b, int *sizes, int index)
{
	int	j;
	int	cluster_size;

	if (sizes[index] == 0)
		return ;
	cluster_size = sizes[index];
	j = 0;
	while (j < cluster_size)
	{
		pb(a, b);
		rb(b);
		j++;
	}
	divide_into_clusters_recursive(a, b, sizes, index + 1);
}

void	sort_cluster_recursive(t_stack *b, int cluster_size)
{
	int	half;

	if (cluster_size <= 1)
		return ;
	if (is_stack_sorted(b))
		return ;
	if (cluster_size == 2)
	{
		if ((int)(long)(b->top->content) > (int)(long)(b->top->next->content))
			sb(b);
		return ;
	}
	if (cluster_size == 3)
	{
		sort_cluster_three(b);
		return ;
	}
	half = cluster_size / 2;
	sort_cluster_recursive(b, half);
	sort_cluster_recursive(b, cluster_size - half);
}
