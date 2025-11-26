/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:07:03 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/26 11:07:03 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_node(t_build *data)
{
	if (data->a.array)
	{
		free(data->a.array);
	}
	if (data->b.array)
	{
		free(data->b.array);
	}
}

void	ft_error(t_build *data)
{
	free_node(data);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
