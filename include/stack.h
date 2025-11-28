/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:02:18 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 11:03:18 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int			*array;
	int			size;
	int			top;
	int			bot;
}				t_stack;

typedef struct s_build
{
	t_stack		a;
	t_stack		b;
}				t_build;

typedef enum s_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B,
}				t_loc;

typedef struct s_chunck
{
	t_loc		loc;
	int			size;
}				t_chunck;

typedef struct s_bucket
{
	t_chunck	low;
	t_chunck	mid;
	t_chunck	high;
}				t_bucket;

#endif