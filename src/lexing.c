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
		*i++;
	len = 0;
	while (str[*i])
	{
		if (is_ifs(str[*i]))
			break;
		len++;
		*i++;
	}
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	*i -= len;
	j = 0;
	while (j < len)
	{
		ret[j] = str[*i];
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

char	**ft_split(char *str, char *delim)
{
	char	**ret;
	int		i;
	int		total_tokens;

	total_tokens = count_tokens(str);
	ret = (char **)malloc(sizeof(char *) * (total_tokens + 1));
	if (!ret)
		return (NULL);
	ret[total_tokens] = ft_strdup("\0");
	i = 0;
	while (str && str[i])
	{
		if (!is_ifs(str[i]))
			ret[i] = copy_token(str, &i);
		i++;
	}
	return (ret);
}

void	lexer(t_shell_data *data)
{
	char **tokens;
	int i;
	int j;

	ft_split(data->input, WHITESPACE)
}
