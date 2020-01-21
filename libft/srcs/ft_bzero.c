/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:02:20 by nforay            #+#    #+#             */
/*   Updated: 2019/12/01 18:40:02 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *str, size_t len)
{
	size_t	pos;

	pos = 0;
	while (pos < len)
	{
		((char*)str)[pos] = 0;
		pos++;
	}
}