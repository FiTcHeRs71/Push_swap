/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:12:59 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:12:59 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		return (NULL);
	}
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/*
FT_LSTNEW (simplified)

NAME
	ft_lstnew -- create a new list node element
SYNOPSIS
	t_list *ft_lstnew(void *content);
DESCRIPTION
	Allocate (with malloc(3)) and return the new element. The member variable
	'content' is initialized with the value of the 'content' parameter.
	The 'next' variable is initialized to NULL.
PARAMETERS
	content: The content of the new element
RETURN VALUES
	The new element.
AUTHORIZED EXTERNAL FUNCTIONS
	malloc(3)
	*/