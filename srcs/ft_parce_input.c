/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssubielo <ssubielo@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:41:32 by ssubielo          #+#    #+#             */
/*   Updated: 2022/08/03 03:23:25 by ssubielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int ft_check_input(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			i++;
			while(input[i] != '\'')
			{
				if(input[i] == '\0')
					return(write(2, "ERROR : WRONG QUOTES\n", 21));
				i++;
			}
		}
		else if (input[i] == '"')
		{
			i++;
			while(input[i] != '"')
                        {
                                if(input[i] == '\0')
					return(write(2, "ERROR : WRONG QUOTES\n", 21));
                                i++;
                        }
               }
		i++;
	}
	return(0);
}

char	**ft_add_cmd(char **cmd_list, char *cmd)
{
	static int i;
	int	j;
	char 	**new_cmd_list;

	j = 0;
	new_cmd_list = calloc(sizeof(char *), i + 2);
	new_cmd_list[i] = cmd;
	while (j < i)
	{
		new_cmd_list[j] = cmd_list[j];
		j++;
	}
	free(cmd_list);
	i++;
	return(new_cmd_list);
}

char    **ft_get_all_cmd(char **cmd_list,char *input)
{
	char *cmd;
	int i;
	int j;
	int e;

	i = 0;
	j = 0;
	e = 0;
	while (input[i] == ' ' && input[i])
		i++;
	while (input[i + j] != ' ' && input[i + j])
                j++;
	if(j != 0)
	{
		cmd = ft_calloc(sizeof(char),j + 1);
		i +=j;
		while(j > 0)
		{
			cmd[e] = input[i - j];
			e++;
			j--;
		}
		cmd_list = ft_add_cmd(cmd_list, cmd);
	}
	if (!input[i])
		return(cmd_list);
	else
		return(ft_get_all_cmd(cmd_list, input + i));
}

char	**ft_parce_input(char *input)
{
	char **cmd_list;

	if (ft_check_input(input))
		return(NULL);
	cmd_list = ft_get_all_cmd(0, input);
	return(cmd_list);
}

int main(int ac, char **av)
{
	char **cmd_list;
	int i;
	
	i = 0;
	cmd_list = 0;
	if (ac < 2)
		return(0);
	cmd_list = ft_parce_input(av[1]);
	if (!cmd_list)
		return(0);
	while (cmd_list[i])
	{
		ft_putstr_rl(cmd_list[i++]);
		write(1, "\n", 1);
	}
}
