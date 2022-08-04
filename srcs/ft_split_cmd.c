/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:17:24 by equesnel          #+#    #+#             */
/*   Updated: 2022/08/04 03:57:43 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	nb_cmd(t_def_char *line)
{
	int	i;
	int	nbc;

	i = 0;
	nbc = 1;
	while (line[i].c)
	{
		if (line[i].c == '|' && line[i].c && line[i].quotes == 0)
			nbc++;
		i++;
	}
	return (nbc);
}

t_def_char	**ft_split_cmd(t_def_char *line)
{
	int		len;
	int		j;
	int		i;
	int		e;
	t_def_char	**cmd;

	len = nb_cmd(line);
	cmd = ft_calloc(sizeof(t_def_char *), len + 1);
	if (!cmd)
		return (NULL);
	e = 0;
	i = 0;
	while (line[i].c)
	{
		j = 0;
		while (!(line[i].c == '|' && line[i].quotes == 0) && line[i].c != 0)
			i++;
		cmd[e] = ft_calloc(sizeof(t_def_char), i + 1);
		while (j < i)
		{
			cmd[e][j].c = line[j].c;
			j++;
		}
		e++;
		i = 0;
		if (line[j].c != 0)
			j++;
		line = line + j;
	}
	return (cmd);
}
