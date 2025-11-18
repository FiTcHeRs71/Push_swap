/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 11/10/2025 09:02:13 by fducrot           #+#    #+#             */
/*   Updated: 11/10/2025 09:12:13 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
	{
		return (0);
	}
}

/*
ISASCII(3) (simplified)

NAME
    isascii -- test for ASCII character
SYNOPSIS
    int isascii(int c)
DESCRIPTION
    The isascii() function tests for an ASCII character, 
	which is any character between 0 and octal 0177 inclusive.*/