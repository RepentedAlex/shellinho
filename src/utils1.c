/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:22:46 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/04 16:22:49 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellinho.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (s);
	i = -1;
	while (++i < n)
		((char *)s)[i] = (char)c;
	return (s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

bool	is_ifs(char c)
{
	int	i;

	i = 0;
	while (IFS[i])
	{
		if (c == IFS[i])
			return (true);
		i++;
	}
	return (false);
}
