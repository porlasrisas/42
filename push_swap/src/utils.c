/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:45:33 by guigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:20:01 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	split_and_store(int argc, char **argv, char **all_args)
{
	int		i;
	int		j;
	int		k;
	char	**numbers;

	i = 1;
	k = 0;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (0);
		j = 0;
		while (numbers[j])
		{
			k = convert_and_store(all_args, k, numbers[j]);
			if (k == 0)
				return (0);
			free(numbers[j++]);
		}
		free(numbers);
		i++;
	}
	all_args[k] = NULL;
	return (k);
}

char	*normalize_zero(char *str)
{
	int		i;
	int		is_negative;
	char	*result;

	i = 0;
	is_negative = 0;
	if (str[0] == '-')
		is_negative = 1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return ("0");
	if (is_negative)
	{
		result = ft_strjoin("-", &str[i]);
		return (result);
	}
	return (&str[i]);
}

int	convert_and_store(char **all_args, int k, char *num_str)
{
	long	num;
	int		i;

	num = ft_atoi(num_str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	i = 0;
	while (i < k)
	{
		if (ft_atoi(all_args[i]) == num)
			return (0);
		i++;
	}
	all_args[k] = ft_strdup(num_str);
	if (!all_args[k])
		return (0);
	return (k + 1);
}
