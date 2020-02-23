/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:08:26 by nforay            #+#    #+#             */
/*   Updated: 2020/02/22 16:17:32 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_args
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	char			*x;
	char			*xcap;
}					t_args;

int					ft_printf(const char *format, ...);
#endif
