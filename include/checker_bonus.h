/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:49:49 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 09:49:52 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../include/push_swap.h"

// checker_utils_bonus.c
bool	exec_push(t_build *data, char *cmd);
bool	exec_reverse_rotate(t_build *data, char *cmd);
bool	exec_rotate(t_build *data, char *cmd);
bool	exec_swap(t_build *data, char *cmd);
bool	execute_instruction(t_build *data, char *cmd);

// main.c
void	ft_cheking_argc_argv(int argc, char **argv, t_build *data);
void	pick_up_instruction_execute(t_build *data);

#endif