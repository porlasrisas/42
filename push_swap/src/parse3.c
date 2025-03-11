/* ************************************************************************** */
/*                                                                            */
/*   parse2b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_into_clusters_recursive(t_stack *a, t_stack *b,
		int *sizes, int index)
{
	int	i;

	if (sizes[index] == 0)
		return ;
	i = 0;
	while (i < sizes[index])
	{
		pb(a, b);
		rb(b);
		i++;
	}
	divide_into_clusters_recursive(a, b, sizes, index + 1);
}

void	sort_cluster_recursive(t_stack *b, int cluster_size)
{
	if (cluster_size <= 1 || is_stack_sorted(b))
		return ;
	if (cluster_size == 2)
	{
		if ((int)(long)(b->top->content) < (int)(long)(b->top->next->content))
			sb(b);
		return ;
	}
	if (cluster_size == 3)
	{
		sort_cluster_three(b);
		return ;
	}
	sort_cluster_recursive(b, cluster_size / 2);
	sort_cluster_recursive(b, cluster_size - (cluster_size / 2));
}

void	sort_all_clusters(t_stack *a, t_stack *b, int *sizes)
{
	int	i;
	int	cluster_size;

	i = 0;
	while (sizes[i] > 0)
	{
		cluster_size = sizes[i];
		while (cluster_size-- > 0)
			pa(a, b);
		final_sweep(a);
		i++;
	}
}
