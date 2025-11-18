/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:13:42 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/11 09:13:42 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len = ft_format(arg, str[i + 1], len);
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

/*
Program name libftprintf.a
Makefile NAME, all, clean, fclean, re
External functs. malloc, free, write,
va_start, va_arg, va_copy, va_end
Libft authorized Yes
Description Write a library that contains ft_printf(), a
function that will mimic the original	printf(void)
*/