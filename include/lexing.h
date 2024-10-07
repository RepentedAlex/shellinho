/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:56:06 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/06 17:56:20 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "shellinho.h"

typedef enum e_lex_cat
{
	COMMAND,
	OPTION,
	ARG,
	PIPE,
	QUOT,
	VAR,
	REDIR
}				t_lex_cat;

typedef struct s_token
{
	char			*value;
	t_lex_cat		lex_cat;
}				t_token;

// ===== LEXING =====

t_token *ft_split(char *str);


// ===== NODE RELATED =====
void	token_add_back(t_token **head, t_token *new);
t_token	*token_goto_last(t_token *head);
t_token	*token_new(char *content);

#endif

// execve char ** {abc, cde, ....., asdfkjj}
// {NULL}
// | && || ;
