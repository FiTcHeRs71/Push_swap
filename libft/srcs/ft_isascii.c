/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:10:11 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:10:11 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
		return (0);
}

/*
ISASCII(3) (simplified)

NAME
    isascii -- test for ASCII character
SYNOPSIS
    int isascii(int c)
DESCRIPTION
    The isascii() function tests for an ASCII character, 
	which is any character between 0 and octal 0177 inclusive.
	*/