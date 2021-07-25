/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:29:29 by arthur            #+#    #+#             */
/*   Updated: 2021/07/25 14:51:40 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/pipex.h"

void	parse_file_in(t_instance *pipex, char *path)
{
	int	fd;

	errno = 0;
	fd = open(path, O_RDONLY);
	if (errno != 0)
	{
		ft_printf("pipex: %s: %s\n", path, strerror(errno));
		destroy_stack();
		exit(1);
	}
	pipex->file_in = fd;
}

char	**get_cmd_args(char *name, int i, char **args)
{
	int		e;
	int		p;
	char	**arg;

	e = 1;
	p = 1;
	arg = new (sizeof(char *), i + 1);
	arg[0] = name;
	while (e < i)
	{
		arg[p] = args[e];
		p++;
		e++;
	}
	arg[p] = NULL;
	return (arg);
}

t_exec_cmd	parse_cmd(const char *str, t_instance *pipex)
{
	t_exec_cmd	cmd;
	char		**args;
	int			i;

	cmd.args = NULL;
	cmd.cmd = NULL;
	i = 0;
	args = ft_split(str, ' ');
	while (args[i])
		i++;
	if (i > 0)
		valid_split(&cmd, pipex, i, args);
	if (!cmd.args)
	{
		cmd.args = new (sizeof(char *), 2);
		cmd.args[0] = "";
		cmd.args[1] = NULL;
	}
	return (cmd);
}

void	handle_args_error(int argc)
{
	if ((argc != 5 && !BONUS) || (argc < 5 && BONUS))
	{
		ft_printf("Wrong argument number: %d\n", argc - 1);
		destroy_stack();
		exit(1);
	}
}

void	parse(t_instance *pipex, int argc, char *argv[])
{
	int		i;

	pipex->cmd = NULL;
	pipex->count_cmd = 0;
	i = 1;
	handle_args_error(argc);
	while (i < argc)
	{
		if (i == 1)
		{
			parse_file_in(pipex, argv[i]);
			i++;
		}
		while (i < argc - 1)
		{
			add_cmd(&pipex->cmd, create_cmd(argv[i]));
			pipex->count_cmd++;
			i++;
		}
		if (i == argc - 1)
			pipex->file_out = argv[i];
		i++;
	}
}
