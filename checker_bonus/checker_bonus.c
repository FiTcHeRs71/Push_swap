#include "../include/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_build	data;
	char	*line;
	char	*trimmed;

	;
	init_data(argc, argv, &data);
	line = get_next_line(0);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
		{
			ft_error(&data);
		}
		execute_instruction(&data, trimmed);
		free(trimmed);
		line = get_next_line(0);
	}
	if (checking_is_already_sort(&data, 1) && current_size(&data.b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_node(&data);
	exit(EXIT_SUCCESS);
}
