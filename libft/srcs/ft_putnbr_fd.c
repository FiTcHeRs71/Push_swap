/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:13:56 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:13:56 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	r;

	nb = n;
	r = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	r = (nb % 10) + 48;
	write(fd, &r, 1);
}

/*
FT_PUTNBR_FD (simplified)

NAME
    ft_putnbr_fd -- write an int on a specified file descriptor
SYNOPSIS
    void ft_putnbr_fd(int n, int fd);
DESCRIPTION
    ft_putnbr_fd() writes the int n on the file descriptor fd
PARAMETERS
    n: int to write
    fd: file descriptor on which to write
RETURN VALUES
    ft_putnbr_fd() does not return anything
AUTHORIZED EXTERNAL FUNCTIONS
    write(2)
	*/