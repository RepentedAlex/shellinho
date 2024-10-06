/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:01:47 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/06 15:01:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"

t_error	display_prompt(t_shell_data *data)
{
	data->input = readline(data->prompt);
	if (!data->input) //Peut arriver si EOF avec string vide, donc pas forcément une erreur.
		return (ERROR);
	return (NO_ERROR);
}

t_error	read_command(t_shell_data *data)
{
	if (!data->input)
		return (ERROR);
	return (NO_ERROR);
}

t_error	interpret_command(t_shell_data *data)
{
	if (!data->input)
		return (ERROR);
	return (NO_ERROR);
}

t_error	exec_command(t_shell_data *data)
{
	if (!data->input)
		return (ERROR);
	return (NO_ERROR);
}
