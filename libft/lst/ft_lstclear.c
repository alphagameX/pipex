/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:14:16 by atinseau          #+#    #+#             */
/*   Updated: 2021/07/25 14:52:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;
	t_list	*next;

	if (!*lst)
		return ;
	s = *lst;
	while (s != NULL)
	{
		next = s->next;
		del(s->content);
		ft_free(s);
		s = next;
	}
	*lst = NULL;
}
