/* ************************************************************************** */
/*                                                                            */
/*   push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!parse_arguments(a, argc, argv) || !check_duplicates(a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (a->size <= 5)
		sort_small(a, b);
	else
	{
		process_clusters_by_value(a, b, 5);
		greedy_insertion_optimized(a, b);
	}
	return (0);
}
