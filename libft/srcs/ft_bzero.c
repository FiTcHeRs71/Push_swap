/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:09:45 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:09:45 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
BZERO(3) (simplified)

NAME
    bzero -- write zeroes to a bye string
SYNOPSIS
    void bzero(void *s, size_t n);
DESCRIPTION
    The bzero() function writes n zeroed bytes to the string s. 
	If n is zero, bzero() does nothing.
	*/