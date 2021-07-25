/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unleak_strjoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:13:46 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 19:58:27 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_unleak_strjoin(char **dst, char *src)
{
	char	*tmp;

	if (!*dst)
	{
		*dst = ft_strdup(src);
		return ;
	}
	tmp = ft_strdup(*dst);
	ft_free(*dst);
	*dst = ft_strjoin(tmp, src);
	ft_free(tmp);
}
