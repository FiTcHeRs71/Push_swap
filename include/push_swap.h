/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:47:13 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/29 11:47:34 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/ft_printf.h"
# include "operations.h"
# include "stack.h"

// op_utlis.c
int		get_value_at(t_stack *stk, int nb);
int		current_size(t_stack *stk);
int		next_top(t_stack *stk, int index);
int		next_bot(t_stack *stk, int index);
bool	array_is_full(t_stack *stk);

// erroc .c
void	ft_error(t_build *data);
void	free_node(t_build *data);
void	cleanup_and_error(t_build *data, int *numbers);

// chunck_stack.c
void	chunck_stack(t_build *data);
void	sort_chunk(t_build *data, t_chunck *to_chunck);
void	sort_one(t_build *data, t_chunck *to_chunck);
void	sort_two(t_build *data, t_chunck *to_chunck);

// sort_optimize.c
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

// chunck_split.c
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

// ft_execute.c
void	ft_execute(t_build *data);
void	quick_three(t_build *data);
void	quick_five(t_build *data);

// sort_hunk.c
void	chunck_stack(t_build *data);
bool	check_arg_is_digit(char *str);
bool	check_duplicate_numbers(int *elements, int len);
int		ft_counter(char *s, char c);

// stack_initz.c
void	numbers_mapping(int *numbers, int *rank, int len);
void	fill_stack(t_build *data, t_stack *stk, int len, char **argv);
void	init_stack(t_build *data, t_stack *stk, int len);
void	checking_elements(char **elements, int size);
void	init_data(int argc, char **argv, t_build *data);

// ft_parsing.c
void	ft_parsing(char **argv, t_build *data);
char	*ft_concat_args(char **argv, char *line, t_build *data);
void	ft_define_flag(t_build *data);
#endif