#include "../include/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_build *data;

	init_data(argc, argv, data);
	

	if (is_sorted(&data->a))
	{
		ft_printf("OK\n");
	}
	else
	{
		ft_printf("KO\n");
	}
}