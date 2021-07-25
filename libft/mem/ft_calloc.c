/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:11:29 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/09 15:33:29 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (char *)new (size, nmemb);
	if (!ptr)
		return (NULL);
	ft_memset((void *)ptr, 0, size * nmemb);
	return ((void *)ptr);
}
