/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_logistics_initz.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:45:39 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/25 18:32:48 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void print_stack(t_stack *stk)
{
    int i;
    int size;
    
    size = current_size(stk);
    i = 1;
    while (i <= size)
    {
        printf("%d\n", set_up_value(stk, i));
        i++;
    }
}

void	numbers_mapping(int *numbers, int *rank ,int len)
{
	int	i;
	int	j;
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
		printf("le rank est : %d\n",rank[i]); // attention
		i++;
	}
}

void	fill_stack(t_build *data, t_stack *stk, int len, char **argv)
{
	int		*numbers;
	size_t 	i;
	
	i = 1;
	numbers = malloc(len * sizeof(int));
	if (!numbers)
	{
		ft_error(data);
	}
	while(argv[i]) // rempis la stack 
	{
		if (!check_arg_is_digit(argv[i]))
			{
				ft_error(data);
			}
		numbers[i - 1] = ft_atoi (argv[i]);
		i++;
	}
	check_duplicate_numbers(data, numbers, len);
	numbers_mapping(numbers, stk->stack, len);
	stk->bot = len - 1;
	free(numbers);
}

void	init_stack(t_build *data, t_stack *stk, int len)
{
	stk->stack = malloc(len * sizeof(int));
	if (!stk->stack)
	{
		ft_error(data);
	}
	stk->top = 0;
	stk->bot = 0;
	stk->size = len;
	ft_bzero(stk->stack, len);
}

void	init_data(int argc, char **argv, t_build *data)
{
	argc--;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	printf("=====before swap=====\n");
	print_stack(&data->a);
	//push_b(data);
	//rotate_a(data);
	//printf("=====after swap=====\n");
	//print_stack(&data->a);
	//print_stack(&data->b);
	//printf("push a : %d\n", data->a.stack[0]);
}

// enlever les printf