/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:57:06 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/06 17:57:08 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"
#include "lexing.h"

char	*copy_token(const char *str, int *i)
{
	char	*ret;
	int		len;
	int		j;

	while (is_ifs(str[*i]))
		*i += 1;
	len = 0;
	while (str[*i])
	{
		if (is_ifs(str[*i]))
			break ;
		len++;
		*i += 1;
	}
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	*i -= len;
	j = 0;
	while (j < len)
	{
		ret[j] = str[*i];
		*i += 1;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

int	count_tokens(const char *str)
{
	int		ret;
	int		i;
	bool	is_word;

	i = 0;
	ret = 0;
	is_word = false;
	while (str && str[i])
	{
		if (!is_ifs(str[i]) && !is_word)
		{
			is_word = true;
			ret++;
		}
		else if (is_ifs(str[i]) && is_word)
			is_word = false;
		i++;
	}
	return (ret);
}

t_token *ft_split(char *str)
{
	t_token	*ret;
	int		i;
	int		j;
	int		total_tokens;

	total_tokens = count_tokens(str);
	ret = (t_token *)malloc(sizeof(t_token) * (total_tokens + 1));
	if (!ret)
		return (NULL);
	ret[total_tokens].value = ft_strdup("\0");
	i = 0;
	j = 0;
	while (j < total_tokens)
	{
		if (!is_ifs(str[i]))
			ret[j].value = copy_token(str, &i);
		i++;
		j++;
	}
	return (ret);
}

void	lexer(t_shell_data *data)
{
	t_token	*token_array;

	token_array = ft_split(data->input);
	if (!token_array)
		return ;
	data->token_array = token_array;
}
