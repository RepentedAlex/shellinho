/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:42:13 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 17:42:33 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"
#include "exit.h"

void ft_exit(t_shell_data *data)
{
	if (data->prompt)
		free(data->prompt);
	if (data->input)
		free(data->input);
}
