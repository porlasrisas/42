/* ************************************************************************** */
/*                                                                            */
/*   parse2a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cluster_sizes_recursive(int total_size, int *sizes, int *index)
{
	if (total_size <= 5)
	{
		sizes[*index] = total_size;
		(*index)++;
		return ;
	}
	sizes[*index] = total_size / 2;
	(*index)++;
	get_cluster_sizes_recursive(total_size - (total_size / 2),
		sizes, index);
}

int	*get_cluster_sizes(int total_size)
{
	int	*sizes;
	int	index;

	sizes = malloc((total_size + 1) * sizeof(int));
	if (!sizes)
		return (NULL);
	index = 0;
	get_cluster_sizes_recursive(total_size, sizes, &index);
	sizes[index] = 0;
	return (sizes);
}
