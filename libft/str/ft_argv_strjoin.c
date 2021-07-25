/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:14:46 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 15:26:21 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

void	ft_argv_strjoin(char **dst, int count, ...)
{
	va_list	list;
	int		i;

	i = 0;
	va_start(list, count);
	while (i < count)
	{
		ft_unleak_strjoin(dst, va_arg(list, char *));
		i++;
	}
}
