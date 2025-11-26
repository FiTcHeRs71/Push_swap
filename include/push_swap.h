/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:23:43 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/26 10:24:08 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"
# include "stack.h"
# include "../libft/include/ft_printf.h"

// op_utlis.c
int		get_value_at(t_stack *stk, int nb);
int		current_size(t_stack *stk);
int		next_top(t_stack *stk, int index);
int		next_bot(t_stack *stk, int index);
bool	array_is_full(t_stack *stk);

// erroc .c
void	ft_error(t_build *data);
void	free_node(t_build *data);

// chunck_stack.c
void	chunck_stack(t_build *data);
void	sort_chunk(t_build *data, t_chunck *to_chunck);
void	sort_one(t_build *data, t_chunck *to_chunck);
void	sort_two(t_build *data, t_chunck *to_chunck);

// check_quick_sort.c
void	check_quick_sort(t_build *data, t_chunck *to_chunck);
void	quick_sort_second(t_build *data, t_chunck *to_chunck);
void	process_top_b(t_build *data, t_chunck *to_chunck);
void	process_bot_a(t_build *data, t_chunck *to_chunck);
void	process_bot_b(t_build *data, t_chunck *to_chunck);

// chunck_utils.c
int		chunk_get_nth(t_build *data, t_chunck *chunck, int n);
t_stack	*loc_to_stack(t_build *data, t_loc loc);
void	update_top(t_build *data, t_chunck *to_chunck);
int		chunk_find_max(t_build *data, t_chunck *chunck);

// change_stack.c
int		change_stack(t_build *data, t_loc src, t_loc dest);
void	move_from_bottom_b(t_build *data, t_loc dest);
void	move_from_bottom_a(t_build *data, t_loc dest);
void	move_from_top_a(t_build *data, t_loc dest);
void	move_from_top_b(t_build *data, t_loc dest);

// sort_three.c
void	sort_three(t_build *data, t_chunck *to_chunck);
void	process_three_top_a(t_build *data, t_chunck *to_chunck, t_stack *stk,
			int max);
void	process_three_top_b(t_build *data, t_chunck *to_chunck, t_stack *stk,
			int max);
void	process_three_bot_a(t_build *data, t_chunck *to_chunck, t_stack *stk,
			int max);
void	process_three_bot_b(t_build *data, t_chunck *to_chunck, t_stack *stk,
			int max);

// split_chunck.c
void	split_chunk(t_build *data, t_chunck *to_chunck, t_bucket *dest);
void	init_size(t_chunck *low, t_chunck *mid, t_chunck *high);
void	setup_loc_split(t_loc loc, t_chunck *low, t_chunck *mid,
			t_chunck *high);
void	setup_pivots(t_loc loc, int max_size, int *pivot_1, int *pivot_2);

// split_utils.c
void	max_update_adjust(t_build *data, t_chunck *high);
bool	checking_is_already_sort(t_build *data, int start);
bool	check_consecutive(int a, int b, int c, int d);
void	swap_three_numbers(int *a, int *b, int *c);

#endif