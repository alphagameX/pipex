/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:15 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/09 15:33:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = new(sizeof(t_list), 1);
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->next = NULL;
	return (cell);
}
