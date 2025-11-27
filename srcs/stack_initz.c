/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:30:09 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 09:30:22 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	numbers_mapping(int *numbers, int *rank, int len)
{
	int		i;
	int		j;
	size_t	counter;

	i = 0;
	while (i < len)
	{
		j = 0;
		counter = 0;
		while (j < len)
		{
			if (numbers[j] <= numbers[i])
			{
				counter++;
			}
			j++;
		}
		rank[i] = counter;
		i++;
	}
}

void	fill_stack(t_build *data, t_stack *stk, int len, char **argv)
{
	int		*numbers;
	size_t	i;

	i = 1;
	numbers = malloc(len * sizeof(int));
	if (!numbers)
	{
		ft_error(data);
	}
	while (argv[i])
	{
		if (!check_arg_is_digit(argv[i]))
		{
			free(numbers);
			ft_error(data);
		}
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	check_duplicate_numbers(data, numbers, len);
	numbers_mapping(numbers, stk->array, len);
	stk->bot = len - 1;
	free(numbers);
}
void	fill_stack_split(t_build *data, t_stack *stk, int len, char **argv)
{
	int		*numbers;
	size_t	i;

	i = 0;
	numbers = malloc(len * sizeof(int));
	if (!numbers)
	{
		ft_error(data);
	}
	while (argv[i])
	{
		if (!check_arg_is_digit(argv[i]))
		{
			ft_error(data);
		}
		numbers[i] = ft_atoi(argv[i]);
		i++;
	}
	check_duplicate_numbers(data, numbers, len);
	numbers_mapping(numbers, stk->array, len);
	stk->bot = len - 1;
	free(numbers);
}

void	init_stack(t_build *data, t_stack *stk, int len)
{
	stk->array = malloc(len * sizeof(int));
	if (!stk->array)
	{
		ft_error(data);
	}
	stk->top = 0;
	stk->bot = 0;
	stk->size = len;
	ft_bzero(stk->array, len);
}
