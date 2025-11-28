/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:53:27 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 11:04:52 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_node(t_build *data)
{
	if (data && data->a.array)
	{
		free(data->a.array);
	}
	if (data && data->b.array)
	{
		free(data->b.array);
	}
}

void	ft_error(t_build *data)
{
	free_node(data);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
