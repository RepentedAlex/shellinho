/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:21:04 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 17:21:06 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"

t_error	set_prompt(t_shell_data *data)
{
	data->prompt = ft_strdup(PROMPT);
	if (!data->prompt)
		return (ERROR);
	return (NO_ERROR);
}
