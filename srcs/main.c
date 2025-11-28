/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:08:04 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 13:22:36 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_build		data;
	t_bucket	bucket;
	t_chunck	chunk;
	t_stack		stack;

	if (argc <= 1)
		return (0);
	if (argc == 2 && !*argv[1])
		return (0);
	ft_memset(&data, 0, sizeof(data));
	ft_memset(&bucket, 0, sizeof(bucket));
	ft_memset(&chunk, 0, sizeof(chunk));
	ft_memset(&stack, 0, sizeof(stack));
	ft_parsing(argv, &data);
	ft_execute(&data);
	free_node(&data);
	exit(EXIT_SUCCESS);
}
	/*if (argc => 2 && argv[1][0])
	{
		size = ft_counter(argv[1], ' ');
		elements = ft_split(argv[1], ' ');
		checking_elements(elements, size);
		init_data_split(size, elements, &data);
		ft_free_2d_array(elements, size);
	}
	else if (argc > 2)
	{
		init_data(argc - 1, argv, &data);
	}
	else
		return(ft_error(&data), 1);*/