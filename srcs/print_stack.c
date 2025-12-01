/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:21:09 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/26 10:24:43 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stk)
{
	int	i;
	int	size;

	size = current_size(stk);
	i = 1;
	while (i <= size)
	{
		printf("%d\n", get_value_at(stk, i));
		i++;
	}
}
