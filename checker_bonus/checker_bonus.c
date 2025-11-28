/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:07:30 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 15:07:46 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_build	data;
	t_stack	stack;

	if (argc <= 1)
		return (0);
	if (argc == 2 && !*argv[1])
		return (0);
	ft_memset(&data, 0, sizeof(data));
	ft_memset(&stack, 0, sizeof(stack));
	ft_parsing(argv, &data);
	pick_up_instruction_execute(&data);
	if (checking_is_already_sort(&data, 1) && current_size(&data.b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_node(&data);
	exit(EXIT_SUCCESS);
}

void	ft_cheking_argc_argv(int argc, char **argv, t_build *data)
{
	int		size;
	char	**elements;

	if (argc == 2)
	{
		elements = ft_split(argv[1], ' ');
		size = ft_counter(argv[1], ' ');
		checking_elements(elements, size);
		init_data(size, elements, &(*data));
		ft_free_2d_array(elements, size);
	}
	else if (argc > 2)
		init_data(argc, argv, &(*data));
}

void	pick_up_instruction_execute(t_build *data)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(0);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (!trimmed)
			ft_error(data);
		if (!execute_instruction(data, trimmed))
		{
			ft_error(data);
		}
		free(trimmed);
		line = get_next_line(0);
	}
}
