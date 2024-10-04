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
	return (0);
}
