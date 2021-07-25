/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:35:41 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 13:19:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

t_cmd	*create_cmd(char *cmd)
{
	t_cmd	*new_cmd;

	new_cmd = new (sizeof(t_cmd), 1);
	new_cmd->cmd = cmd;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	add_cmd(t_cmd **old, t_cmd *new)
{
	t_cmd	*ptr;

	if (!*old)
	{
		*old = new;
		return ;
	}
	ptr = *old;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

void	print_cmd(t_cmd *cmd)
{
	while (cmd != NULL)
	{
		ft_printf("%s\n", cmd->cmd);
		cmd = cmd->next;
	}
}
