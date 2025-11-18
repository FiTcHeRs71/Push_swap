/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:13:03 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:13:03 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
FT_LSTSIZE (simplified)

NAME
	ft_lstsize -- returns the number of element in the list
SYNOPSIS
	int *ft_lstsize(t_list *lst);
DESCRIPTION
	Count the number of elements of the list
PARAMETERS
	lst: start of the list
RETURN VALUES
	The size of the list
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/