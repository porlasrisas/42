/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:40:12 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:21:09 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
		len++;
	}
	if (len > 10)
		return (0);
	return (1);
}

int	parse_arguments(t_stack *a, int argc, char **argv)
{
	int		i;
	long	num;
	t_list	*new_node;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num == 0 && argv[i][0] != '0')
			return (0);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		new_node = ft_lstnew((void *)(long)num);
		if (!new_node)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		ft_lstadd_back(&(a->top), new_node);
		a->size++;
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_list	*current;
	t_list	*runner;
	int		current_value;
	int		runner_value;

	current = a->top;
	while (current)
	{
		current_value = (int)(long)(current->content);
		runner = current->next;
		while (runner)
		{
			runner_value = (int)(long)(runner->content);
			if (current_value == runner_value)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}
