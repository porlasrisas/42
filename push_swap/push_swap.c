/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:51:41 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 20:30:00 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static char	**build_new_argv(char **tokens, int token_count)
{
	char	**new_argv;
	int		i;

	new_argv = malloc((token_count + 2) * sizeof(char *));
	if (!new_argv)
		return (NULL);
	new_argv[0] = "push_swap";
	i = 0;
	while (i < token_count)
	{
		new_argv[i + 1] = tokens[i];
		i++;
	}
	new_argv[i + 1] = NULL;
	return (new_argv);
}

static void	free_all(char **a, char **b)
{
	free(a);
	free(b);
}

static int	process_single_arg(t_stack *a, char *arg)
{
	char	**tokens;
	char	**new_argv;
	int		token_count;

	tokens = ft_split(arg, ' ');
	if (!tokens) return (0);
	token_count = 0;
	while (tokens[token_count])
		token_count++;
	new_argv = build_new_argv(tokens, token_count);
	if (!new_argv)
	{
		free_split_args(tokens);
		return (0);
	}
	if (!parse_arguments(a, token_count + 1, new_argv) || !check_duplicates(a))
	{
		ft_putstr_fd("Error\n", 2);
		free_split_args(new_argv);
		return (0);
	}
	free_all(new_argv, tokens);
	return (1);
}

static void	process_clusters(t_stack *a, t_stack *b)
{
	int	*sizes;

	sizes = get_cluster_sizes(a->size);
	divide_into_clusters_recursive(a, b, sizes, 0);
	sort_all_clusters(a, b, sizes);
	final_sweep(a);
	free(sizes);
}

int	main(int argc, char **argv)
{
	t_stack	a = {NULL, 0}, b = {NULL, 0};

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		if (!process_single_arg(&a, argv[1]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	else if (!parse_arguments(&a, argc, argv) || !check_duplicates(&a))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (a.size <= 5)
	{
		sort_small(&a, &b);
		return (0);
	}
	process_clusters(&a, &b);
	return (0);
}
