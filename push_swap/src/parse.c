/* ************************************************************************** */
/*                                                                            */
/*   parse1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/10 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*cur;

	if (!stack->top)
		return (1);
	cur = stack->top;
	while (cur->next)
	{
		if ((int)(long)(cur->content) > (int)(long)(cur->next->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	parse_arguments(t_stack *a, int argc, char **argv)
{
	int		i;
	int		num;
	t_list	*node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		node = ft_lstnew((void *)(long)num);
		if (!node)
			return (0);
		ft_lstadd_back(&a->top, node);
		a->size++;
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_list	*cur;
	t_list	*runner;

	cur = stack->top;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if ((int)(long)(cur->content) == (int)(long)(runner->content))
				return (0);
			runner = runner->next;
		}
		cur = cur->next;
	}
	return (1);
}

char	*normalize_zero(char *str)
{
	while (*str == '0')
		str++;
	if (*str == '\0')
		return ("0");
	return (str);
}
