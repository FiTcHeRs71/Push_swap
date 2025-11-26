/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/11/2025 16:14:49 by fducrot           #+#    #+#             */
/*   Updated: 26/11/2025 10:09:41 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *stk)
{
	int	temp;

	temp = stk->array[stk->top];
	stk->array[stk->top] = 0;
	stk->top = next_bot(stk, stk->top);
	stk->bot = next_bot(stk, stk->bot);
	stk->array[stk->bot] = temp;
}

void	rotate_a(t_build *data)
{
	rotate(&data->a);
	ft_printf("ra\n");
}

void	rotate_b(t_build *data)
{
	rotate(&data->b);
	ft_printf("rb\n");
}

void	rotate_a_b(t_build *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_printf("rr\n");
}
