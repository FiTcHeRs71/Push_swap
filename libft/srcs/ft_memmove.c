/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 11/10/2025 09:02:13 by fducrot           #+#    #+#             */
/*   Updated: 11/10/2025 09:02:13 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
	{
		return (dst);
	}
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*
MEMMOVE(3) (simplified)

NAME
    memmove -- copy byte string
SYNOPSIS
    void *memmove(void *dst, const void *src, size_t len);
DESCRIPTION
    The memmove() function copies len bytes from string src to string dst.
    The two strings may overlap; the copy is always done in a non-destructive 
	manner.
RETURN VALUES
    The memmove() function returns the original value of dst.
	*/