/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initz_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:11:47 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 17:11:47 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_data(int argc, char **argv, t_build *data)
{
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	if (checking_is_already_sort(data, 1))
	{
		free_node(data);
		exit(EXIT_SUCCESS);
	}
}

