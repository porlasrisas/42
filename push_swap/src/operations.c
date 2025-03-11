/* ************************************************************************** */
/*                                                                            */
/*   operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	tmp = (int)(long)(first->content);
	first->content = second->content;
	second->content = (void *)(long)tmp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
