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

t_error	interpreter_loop(t_shell_data *data)
{
	bool	test;

	test = true;
	while (test)
	{
		//TODO Display the prompt
		if (display_prompt(data))
			break ;

		//TODO Read the command
		if (read_command(data))
			break ;

		//TODO Interpret the command
		if (interpret_command(data))
			break ;

		//TODO Execute the command
		if (exec_command(data))
			break ;

		//TODO Free the input
		free(data->input);
		data->input = NULL;
		test = false;
	}
	return (NO_ERROR);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell_data	data;

	(void)envp;
	(void)argc;
	(void)argv;
	ft_memset(&data, 0, sizeof(data));
	if (set_prompt(&data))
		return (ERROR);
	interpreter_loop(&data);
	ft_exit(&data);
	return (0);
}
