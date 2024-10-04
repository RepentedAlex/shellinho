/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:58:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"

int main()
{
	t_shell_data	data;

	while (27)
	{
		input = readline(prompt);
		if (!ft_strcmp(input, "exit"))
			break;
		printf("%s\n", input);
	}
	return (0);
}
