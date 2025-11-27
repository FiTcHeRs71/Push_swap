/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:33:58 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 10:33:58 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_build	data;
	char	**elements;
	int		size;

	if (argc == 1)
	{
		return (0);
	}
	if (argc == 2)
	{
		elements = ft_split(argv[1], ' ');
		size = ft_counter(argv[1], ' ');
		checking_elements(elements, size);
		init_data_split(size, elements, &data);
		ft_free(elements, size);
	}
	else if (argc > 2)
	{
		init_data(argc - 1, argv, &data);
	}
	ft_parsing(&data);
	free_node(&data);
	exit(EXIT_SUCCESS);
}
