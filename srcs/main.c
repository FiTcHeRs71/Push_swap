/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:55:23 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 07:56:14 by fducrot          ###   ########.ch       */
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
		init_data(size, elements, &data);
	}
	else if (argc > 2)
	{
		argc--;
		init_data(argc, argv, &data);
	}
	ft_parsing(&data);
	free_node(&data);
	exit(EXIT_SUCCESS);
}
