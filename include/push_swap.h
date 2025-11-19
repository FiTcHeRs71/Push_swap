#ifndef PUSH_SWAP_H
# define PUSH_SWAP__H

# include "stack.h"

// op_utlis.c
int	current_size(t_stack *stk);
int	next_top_free(t_stack *stk, int index);
int	next_bot_free(t_stack *stk, int index);

// swap_op.c
void	swap(t_stack *stk);
void	swap_b(t_build *data);
void	swap_a(t_build *data);
void	swap_a_b(t_build *data);

// push_op.c
void	push(t_stack *src, t_stack *dest);
void	push_a(t_build *data);
void	push_b(t_build *data);

#endif