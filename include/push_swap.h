#ifndef PUSH_SWAP_H
# define PUSH_SWAP__H

# include "stack.h"

// op_utlis.c
int		set_up_value(t_stack *stk, int nb);
int		current_size(t_stack *stk);
int		next_top(t_stack *stk, int index);
int		next_bot(t_stack *stk, int index);
bool	array_is_full(t_stack *stk);

// swap_op.c
void	swap(t_stack *stk);
void	swap_b(t_build *data);
void	swap_a(t_build *data);
void	swap_a_b(t_build *data);

// push_op.c
void	push(t_stack *src, t_stack *dest);
void	push_a(t_build *data);
void	push_b(t_build *data);

// rotate_op.c
void	rotate(t_stack *stk);
void	rotate_a(t_build *data);
void	rotate_b(t_build *data);
void	rotate_a_b(t_build *data);

// reverse_rotate_op.c
void	reverse_rotate(t_stack *stk);
void	reverse_rotate_a(t_build *data);
void	reverse_rotate_b(t_build *data);
void	reverse_rotate_a_b(t_build *data);

// chunck_stack.c
void	chunck_stack(t_build *data);
void	go_to_chunck(t_build *data, t_chunck *to_chunck);
void	sort_one(t_build *data, t_chunck *to_chunck);
void	sort_two(t_build *data, t_chunck *to_chunck);

//check_quick_sort.c
void	check_quick_sort(t_build *data, t_chunck *to_chunck);
void	quick_sort_second(t_build *data, t_chunck *to_chunck);
void	process_top_b(t_build *data, t_chunck *to_chunck);
void	process_bot_a(t_build *data, t_chunck *to_chunck);
void	process_bot_b(t_build *data, t_chunck *to_chunck);

//chunck_utils.c
int		chunck_value(t_build *data, t_chunck *chunck, int n);
t_stack	*loc_to_stack(t_build *data, t_loc loc);
void	define_new_top(t_build *data, t_chunck *to_chunck);
int	setup_max_size(t_build *data, t_chunck *chunck);
int	chunck_the_value(t_build *data, t_chunck *chunck, int n);

//change_stack.c
int		change_stack(t_build *data, t_loc src, t_loc dest);
void	move_to_top_b(t_build *data, t_loc dest);
void	move_to_top_a(t_build *data, t_loc dest);
void	move_to_bot_b(t_build *data, t_loc dest);
void	move_to_bot_a(t_build *data, t_loc dest);

//sort_three.c
void	sort_three(t_build *data, t_chunck *to_chunck);
void	process_three_top_a(t_build *data, t_chunck *to_chunck, t_stack *stk, int max);
void	process_three_top_b(t_build *data, t_chunck *to_chunck, t_stack *stk, int max);
void	process_three_bot_a(t_build *data, t_chunck *to_chunck, t_stack *stk, int max);
void	process_three_bot_b(t_build *data, t_chunck *to_chunck, t_stack *stk, int max);

// split_chunck.c
void	split_chunk(t_build *data, t_chunck *to_chunck, t_bucket *dest);
void	init_size(t_chunck *low, t_chunck *mid, t_chunck *high);
void	setup_loc_split(t_loc loc, t_chunck *low, t_chunck *mid, t_chunck *high);
void	setup_pivots(t_loc loc, int max_size, int *pivot_1, int *pivot_2);
#endif