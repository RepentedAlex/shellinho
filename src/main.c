/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:58:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 17:31:31 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"
#include "exit.h"

t_error	exec_command(t_shell_data *data)
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

t_error	read_command(t_shell_data *data)
{
	if (!data->input)
		return (ERROR);
	return (NO_ERROR);
}

t_error	display_prompt(t_shell_data *data)
{
	data->input = readline(data->prompt);
	if (!data->input) //Peut arriver si EOF avec string vide, donc pas forcément une erreur.
		return (ERROR);
	return (NO_ERROR);
}

int main()
{
	t_shell_data	data;

	if (set_prompt(&data))
		return (ERROR);
	while (1)
	{
		data.input = readline(data.prompt);
		if (!ft_strcmp(data.input, "exit"))
			break;
		printf("%s\n", data.input);
	}
	ft_exit(&data);
	return (0);
}
