/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellinho.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:43:40 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 16:53:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLINHO_H
# define SHELLINHO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "shellinho-> "

typedef bool	t_error;

# define ERROR 1
# define NO_ERROR 0

// ===== STRUCTURES =====
typedef struct	s_shell_data
{
	char	*prompt;
	char	*input;
	int		last_exit_status;
}				t_shell_data;

// ===== UTILITARIES =====
int	ft_strcmp(const char *s1, const char *s2);

#endif
