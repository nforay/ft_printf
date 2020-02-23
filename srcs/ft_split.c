/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:48:11 by nforay            #+#    #+#             */
/*   Updated: 2020/02/02 11:03:01 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		splitnbr(const char *str, char c)
{
	size_t	i;
	size_t	score;
	size_t	j;

	i = -1;
	score = 0;
	while (str[++i])
	{
		if (ft_strchr(&c, str[i]))
			continue ;
		j = i + 1;
		while (!(ft_strchr(&c, str[j])) && str[j])
			j++;
		score++;
		if (str[(i = j)] == '\0')
			return (score);
	}
	return (score);
}

static void			*abort_split(char **splitted, size_t n)
{
	while (n--)
	{
		free(splitted[n]);
		splitted[n] = NULL;
	}
	free(splitted);
	splitted = NULL;
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splitted;
	size_t	n;

	if (!s || !c)
		return (NULL);
	if (!(splitted = ft_calloc(splitnbr(s, c) + 1, sizeof(splitted))))
		return (NULL);
	n = 0;
	i = -1;
	while (s[++i])
		if (!(ft_strchr(&c, s[i])))
		{
			j = i + 1;
			while (!(ft_strchr(&c, s[j])))
				j++;
			if (!(splitted[n] = ft_substr(s, i, j - i)))
				return (abort_split(splitted, n));
			n++;
			i = (j - 1);
		}
	splitted[n] = NULL;
	return (splitted);
}
