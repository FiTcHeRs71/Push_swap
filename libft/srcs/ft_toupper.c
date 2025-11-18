/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 11/10/2025 09:02:13 by fducrot           #+#    #+#             */
/*   Updated: 11/10/2025 09:15:30 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

/*
TOUPPER(3) (simplified)

NAME
    toupper -- lower case to upper case letter conversion
SYNOPSIS
    int toupper(int c);
DESCRIPTION
    The toupper() function converts a lower-case letter to the corresponding
	 upper-case letter. The argument must be representable as an unsigned char 
	 or the value of EOF.
RETURN VALUES
    If the argument is a lower-case letter, the toupper() function returns 
	the corresponding upper-casse letter if there is one; otherwise, the 
	argument is returned unchanged.
	*/