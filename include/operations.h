/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 26/11/2025 07:52:11 by fducrot           #+#    #+#             */
/*   Updated: 26/11/2025 10:16:39 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

// swap_op.c
void	swap(t_stack *stk);
void	swap_b(t_build *data);
void	swap_a(t_build *data);
void	swap_a_b(t_build *data);

// push_op.c
void	push(t_stack *src, t_stack *dest);
void	push_a(t_build *data);
void	push_b(t_build *data);

// rotate_op.c
void	rotate(t_stack *stk);
void	rotate_a(t_build *data);
void	rotate_b(t_build *data);
void	rotate_a_b(t_build *data);

// reverse_rotate_op.c
void	reverse_rotate(t_stack *stk);
void	reverse_rotate_a(t_build *data);
void	reverse_rotate_b(t_build *data);
void	reverse_rotate_a_b(t_build *data);

#endif