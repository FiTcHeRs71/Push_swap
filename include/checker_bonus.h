#ifndef CHECKER_H
# define CHECKER_H

# include "../include/push_swap.h"

// checker_bonus.c
//bool	is_sorted(t_stack *stk);

// checker_utils_bonus.c
bool	exec_push(t_build *data, char *cmd);
bool	exec_reverse_rotate(t_build *data, char *cmd);
bool	exec_rotate(t_build *data, char *cmd);
bool	exec_swap(t_build *data, char *cmd);
bool	execute_instruction(t_build *data, char *cmd);

#endif