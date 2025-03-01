/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:51:41 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:20:14 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_list	*current;
	int		value;

	current = stack->top;
	while (current)
	{
		value = (int)(long)(current->content);
		ft_printf("%d\n", value);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*sizes;

	a.top = NULL;
	b.top = NULL;
	a.size = 0;
	b.size = 0;
	if (!parse_arguments(&a, argc, argv) || !check_duplicates(&a))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (is_stack_sorted(&a))
		return (0);
	sizes = get_cluster_sizes(a.size);
	divide_into_clusters_recursive(&a, &b, sizes, 0);
	sort_all_clusters(&a, &b, sizes);
	final_sweep(&a);
	free(sizes);
	return (0);
}
