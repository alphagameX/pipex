/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:49:54 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:50:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

void	valid_split(t_exec_cmd *cmd, t_instance *pipex, int i, char **args)
{
	cmd->cmd = try_to_get_path(pipex->path, args[0]);
	if (cmd->cmd)
		cmd->valid = 1;
	else
	{
		cmd->valid = 0;
		cmd->cmd = args[0];
	}
	if (i > 1)
		cmd->args = get_cmd_args(cmd->cmd, i, args);
}
