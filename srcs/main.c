
#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

int main	(int argc, char **argv)
{
	t_build	data;

	init_data(argc, argv, &data);
	ft_parsing(&data);
	free_node(&data);
	exit(EXIT_SUCCESS);
	//ft_parsing(&data);
}