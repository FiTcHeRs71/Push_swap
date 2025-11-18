/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:12:31 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:12:31 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*
FT_LSTADD_FRONT (simplified)

NAME
	ft_lstadd_front -- Adds a new element at the front of the list
SYNOPSIS
	void ft_lstadd_front(t_list **lst, t_list *new);
DESCRIPTION
	Add the 'new' element at the front of the list
PARAMETERS
	lst: pointer address to the first element of the list
	new: pointer address of the new element to add to the list
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/