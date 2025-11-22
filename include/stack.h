
#ifndef STACK_H
# define STACK_H


# include <stdbool.h>
# include <limits.h>
# include <stdio.h>



typedef struct		s_stack
{
	int		*stack;
	int		size;
	int		top;
	int		bot;
}					t_stack;

typedef struct		s_build
{
	t_stack	a;
	t_stack	b;
}					t_build;

// parsing.c
void	ft_parsing(t_build *data);
void	quick_three(t_build *data);
void	quick_five(t_build *data);

bool	check_arg_is_digit(char *str);
void	check_duplicate_numbers(t_build *data, int *numbers, int len);

void	free_node(t_build *data);
void	ft_error(t_build *data);

void	numbers_mapping(int *numbers, int *rank ,int len);
void	fill_stack(t_build *data, t_stack *stk, int len, char **argv);
void	init_stack(t_build *data, t_stack *stk, int len);
void	init_data(int argc, char **argv, t_build *data);

#endif