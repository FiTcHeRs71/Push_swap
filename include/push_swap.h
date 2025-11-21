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

#endif