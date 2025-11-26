/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 24/11/2025 11:00:58 by fducrot           #+#    #+#             */
/*   Updated: 26/11/2025 10:12:08 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_build *data, t_chunck *to_chunck)
{
	t_stack	*stk;
	int		max;

	stk = loc_to_stack(data, to_chunck->loc);
	max = chunk_find_max(data, to_chunck);
	if (to_chunck->loc == TOP_A)
	{
		process_three_top_a(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == BOT_A)
	{
		process_three_bot_a(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == TOP_B)
	{
		process_three_top_b(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == BOT_B)
	{
		process_three_bot_b(data, to_chunck, stk, max);
	}
}

void	process_three_top_a(t_build *data, t_chunck *to_chunck, t_stack *stk,
		int max)
{
	if (stk->array[stk->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stk->array[next_bot(stk, stk->top)] == max)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}

void	process_three_top_b(t_build *data, t_chunck *to_chunck, t_stack *stk,
		int max)
{
	push_a(data);
	if (stk->array[stk->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stk->array[next_bot(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
	{
		push_a(data);
	}
	push_a(data);
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}

void	process_three_bot_a(t_build *data, t_chunck *to_chunck, t_stack *stk,
		int max)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	if (stk->array[stk->top] == max)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stk->array[next_bot(stk, stk->top)] == max)
	{
		reverse_rotate_a(data);
	}
	else
	{
		push_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}

void	process_three_bot_b(t_build *data, t_chunck *to_chunck, t_stack *stk,
		int max)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	if (stk->array[stk->top] == max)
	{
		push_a(data);
		reverse_rotate_b(data);
	}
	else if (stk->array[next_bot(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		reverse_rotate_b(data);
	}
	else
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	to_chunck->loc = TOP_B;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}
