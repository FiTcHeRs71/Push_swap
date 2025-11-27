#include "../include/push_swap.h"

void	ft_parsing(char **argv, t_build *data)
{
	size_t		i;
	char		**elements;
	int			size;
	char		*line;

	i = 1;
	size = 0;
	line = '\0';
	while (argv[i])
	{
		line = ft_strjoin(line, argv[i]);
		line = ft_strjoin(line, " ");
		i++;
	}
	elements = ft_split(line, ' ');
	size = ft_counter(line, ' ');
	checking_elements(elements, size);
	init_data(size, elements, data);
	ft_free_2d_array(elements, size);
}
