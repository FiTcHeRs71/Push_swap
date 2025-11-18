/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:15:07 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:15:07 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	if (!s)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

/*
FT_STRMAPI() (simplified)

NAME
    ft_strmapi -- apply a function to each character of a string
SYNOPSIS
    char *ft_strmapi(const char *s, char (*f)(unsigned int, char));
DESCRIPTION
    Apply the function 'f' to each characters in the string 's' 
	to create a new string (with malloc(3)) resulting of the 
	successive applications of 'f'.
PARAMETERS
    s: string over which to iterate
    f: function to apply to each character
RETURN VALUES
    ft_strmapi() returns a new string resulting of the successive 
	applications of 'f'; NULL if the memory allocations failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/