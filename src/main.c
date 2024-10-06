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

t_error interpreter_loop(t_shell_data *data)
{
	while (1)
	{
		//TODO Afficher le prompt
		if (display_prompt(data))
			break;

		//TODO Lire la commande
		if (read_command(data))
			break;

		//TODO Interpréter la commande
		if (interpret_command(data))
			break;

		//TODO Exécuter la commande
		if (exec_command(data))
			break;

		//TODO Free l'input
		free(data->input);
	}
	return (NO_ERROR);
}

int main()
{
	t_shell_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (set_prompt(&data))
		return (ERROR);
	interpreter_loop(&data);
	ft_exit(&data);
	return (0);
}
