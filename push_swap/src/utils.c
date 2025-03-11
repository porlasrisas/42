/* ************************************************************************** */
/*                                                                            */
/*   stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, int value)
{
	t_list	*node;

	node = ft_lstnew((void *)(long)value);
	if (!node)
		return ;
	ft_lstadd_front(&stack->top, node);
	stack->size++;
}


int	pop(t_stack *stack)
{
	t_list	*node;
	int		val;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	val = (int)(long)(node->content);
	free(node);
	return (val);
}
void	rotate_a_to_index(t_stack *a, int index)
{
	int	r;

	if (index <= a->size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		r = a->size - index;
		while (r-- > 0)
			rra(a);
	}
}
void	rotate_b_to_index(t_stack *b, int index)
{
	int	r;

	if (index <= b->size / 2)
	{
		while (index-- > 0)
			rb(b);
	}
	else
	{
		r = b->size - index;
		while (r-- > 0)
			rrb(b);
	}
}
int	cost_rotation(int size, int index)
{
	if (index <= size / 2)
		return (index);
	return (size - index);
}