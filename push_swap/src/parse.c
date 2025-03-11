/* ************************************************************************** */
/*                                                                            */
/*   parse1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:00:00 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/11 00:00:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	free_split(char **arr)
{
	int	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	is_only_spaces(const char *s)
{
	int	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' &&
		    s[i] != '\v' && s[i] != '\f' && s[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_integer(const char *s)
{
	int		i = 0;
	int		sign = 1;
	int		dcount = 0;
	const char	*cmp;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		dcount++;
		i++;
	}
	if (dcount > 10)
		return (0);
	if (dcount == 10)
	{
		if (s[0]=='+' || s[0]=='-')
			cmp = s + 1;
		else
			cmp = s;
		if (sign == 1 && ft_strncmp(cmp, "2147483647", 10) > 0)
			return (0);
		if (sign == -1 && ft_strncmp(cmp, "2147483648", 10) > 0)
			return (0);
	}
	return (1);
}

static long	ft_atol_custom(const char *s)
{
	return ((long)ft_atoi(s));
}

/* Se recorre el arreglo de tokens; se omiten los tokens vacíos */
static int	parse_tokens(t_stack *a, char **toks)
{
	int		i = 0;
	long	num;
	t_list	*node;
	while (toks[i])
	{
		if (toks[i][0] == '\0')
		{
			i++;
			continue;
		}
		if (!is_valid_integer(toks[i]))
			return (0);
		num = ft_atol_custom(toks[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		node = ft_lstnew((void *)(long)num);
		if (!node)
			return (0);
		ft_lstadd_back(&a->top, node);
		a->size++;
		i++;
	}
	return (1);
}

static int	parse_arguments_split(t_stack *a, char *arg)
{
	char	**toks;
	int		ret;
	if (!arg || arg[0] == '\0' || is_only_spaces(arg))
		return (0);
	toks = ft_split(arg, ' ');
	if (!toks)
		return (0);
	ret = parse_tokens(a, toks);
	free_split(toks);
	return (ret);
}

static int	parse_arguments_multi(t_stack *a, int argc, char **argv)
{
	int		i = 1;
	long	num;
	t_list	*node;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (0);
		if (!is_valid_integer(argv[i]))
			return (0);
		num = ft_atol_custom(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		node = ft_lstnew((void *)(long)ft_atoi(argv[i]));
		if (!node)
			return (0);
		ft_lstadd_back(&a->top, node);
		a->size++;
		i++;
	}
	return (1);
}

int	parse_arguments(t_stack *a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || is_only_spaces(argv[1]))
			return (0);
		if (ft_strchr(argv[1], ' '))
			return (parse_arguments_split(a, argv[1]));
	}
	return (parse_arguments_multi(a, argc, argv));
}

int	check_duplicates(t_stack *stack)
{
	t_list	*cur = stack->top;
	t_list	*runner;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if ((int)(long)(cur->content) ==
			    (int)(long)(runner->content))
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
