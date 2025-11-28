/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:21:22 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 14:21:22 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parsing(char **argv, t_build *data)
{
	char	**elements;
	int		size;
	char	*line;

	line = ft_strdup("");
	if (!line)
		ft_error(data);
	line = ft_concat_args(argv, line, data);
	size = ft_counter(line, ' ');
	elements = ft_split(line, ' ');
	if (!*elements)
	{
		free(elements);
		free(line);
		ft_error(data);
	}
	free(line);
	checking_elements(elements, size);
	init_data(size, elements, data);
	ft_free_2d_array(elements, size);
}

char	*ft_concat_args(char **argv, char *line, t_build *data)
{
	size_t	i;
	char	*temp;

	i = 1;
	while (argv[i])
	{
		temp = line;
		line = ft_strjoin(line, argv[i]);
		free(temp);
		if (!line)
		{
			ft_error(data);
		}
		temp = line;
		line = ft_strjoin(line, " ");
		free(temp);
		if (!line)
		{
			ft_error(data);
		}
		i++;
	}
	return (line);
}
