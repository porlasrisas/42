/* ************************************************************************** */
/*                                                                            */
/*   algorithm_value2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_range(t_stack *a, int low, int high)
{
	t_list	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if ((int)(long)(cur->content) >= low && (int)(long)(cur->content) <= high)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}


void	process_cluster(t_stack *a, t_stack *b, int low, int high)
{
	int	pos;

	pos = find_position_in_range(a, low, high);
	while (pos != -1)
	{
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (++pos <= a->size)
				rra(a);
		pb(a, b);
		pos = find_position_in_range(a, low, high);
	}
}

void	process_clusters_by_value(t_stack *a, t_stack *b, int chunks)
{
	int	*sorted;
	int	*bound;
	int	total;
	int	i;

	total = a->size;
	sorted = create_sorted_array(a);
	if (!sorted)
		return ;
	bound = define_boundaries(sorted, total, chunks);
	free(sorted);
	if (!bound)
		return ;
	i = 0;
	while (i < chunks)
	{
		process_cluster(a, b, bound[i], bound[i + 1]);
		i++;
	}
	free(bound);
}
