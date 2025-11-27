/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:15:03 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 07:15:03 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_counter(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while ((s[i] && s[i] != c))
			i++;
	}
	return (count);
}

bool	check_arg_is_digit(char *str)
{
	size_t		i;
	long long	number;
	int			sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		number = (number * 10) + (str[i] - '0');
		if ((sign == 1 && number > INT_MAX) || (sign == -1 && number < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}

void	check_duplicate_numbers(t_build *data, int *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				ft_error(data);
			}
			j++;
		}
		i++;
	}
}
