/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:23:59 by nforay            #+#    #+#             */
/*   Updated: 2019/12/02 22:43:06 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	if (!(ptr = malloc(len + 1)))
		return (NULL);
	s += start;
	ft_memcpy(ptr, s, len);
	ptr[len] = '\0';
 	return (ptr);
}
