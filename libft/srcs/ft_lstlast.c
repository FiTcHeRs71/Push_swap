/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:12:50 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:12:50 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
FT_LSTLAST (simplified)

NAME
	ft_lstlast -- get the last element of the list
SYNOPSIS
	t_list *ft_lstlast(t_list *lst);
DESCRIPTION
	Returns the last element of the list
PARAMETERS
	lst: the start of the list
RETURN VALUES
	Last element of the list
AUTHORIZED EXTERNAL FUNCTIONS
	None
*/