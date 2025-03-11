/* ************************************************************************** */
/*                                                                            */
/*   algorithm_value1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*create_sorted_array(t_stack *a)
{
	int		*arr;
	t_list	*cur;
	int		i;

	arr = malloc(a->size * sizeof(int));
	if (!arr)
		return (NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i] = (int)(long)(cur->content);
		cur = cur->next;
		i++;
	}
	quicksort(arr, 0, a->size - 1);
	return (arr);
}

void	quicksort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2 + 1];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
		quicksort(arr, i, right);
}


int	*define_boundaries(int *sorted, int total, int chunks)
{
	int	*bound;
	int	i;
	int	step;

	bound = malloc((chunks + 1) * sizeof(int));
	if (!bound)
		return (NULL);
	bound[0] = INT_MIN;
	step = total / chunks;
	i = 1;
	while (i < chunks)
	{
		bound[i] = sorted[i * step];
		i++;
	}
	bound[chunks] = INT_MAX;
	return (bound);
}
