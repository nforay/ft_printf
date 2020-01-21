/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 01:12:15 by nforay            #+#    #+#             */
/*   Updated: 2019/12/06 01:39:54 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;
	
	size = 1;
	tmp = lst;
	if (!lst)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
