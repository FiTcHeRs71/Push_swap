/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:12:42 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:12:42 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

/*void	ft_dellst(void* content)
{
	content = NULL;
	return ((void)content);
}*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

/*
FT_LSTDELONE (simplified)

NAME
	ft_lstdelone -- removes one element from the list
SYNOPSIS
	void ft_lstdelone(t_list *lst, void (*del)(void *));
DESCRIPTION
	Free the memory of the element passed as parameter using the 'del' 
	function then free(3). The memory of 'next' must not be freed.
PARAMETERS
	lst: the element to free
	del: address of the function that can delete the element's content
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	free(3)
	*/