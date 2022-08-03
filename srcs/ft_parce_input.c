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

int ft_check_quotes(char *input)
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

int ft_update_stat(char c)
{
	static int stat;
	
	if (c == '\'' && stat == 0)
		stat = 1;
	else if (c == '\'' && stat == 1)
		stat = 0;
	else if (c == '"' && stat == 0)
		stat = 2;
	else if (c == '"' && stat == 2)
		stat = 0;
	return (stat);
}

t_def_char    *ft_modif_line(char *input)
{
	t_def_char *line;
	int i;
	int j;
	int stat;

	i = 0;
	j = 0;
	while (input[i])
	{
		stat = ft_update_stat(input[i]);
		if((input[i] != ' ' || stat != 0) && (input[i] != '\'' || \
			stat == 2) && (input[i] != '"' || stat == 1))
			j++;
		i++;
	}
	line = ft_calloc(sizeof(t_def_char), j + 1);
	i = 0;
	j = 0;
	while (input[i])
	{
		stat = ft_update_stat(input[i]);
		if((input[i] != ' ' || stat != 0) && (input[i] != '\'' || \
			stat == 2) && (input[i] != '"' || stat == 1))
		{
			line[j].c = input[i];
			line[j].quotes = stat;
			//line[j].bool_m = ft_check_meta(line[j].c);	
			j++;
		}
		i++;
	}
	return(line);
}

t_def_char	*ft_parce_input(char *input)
{
	t_def_char *line;

	if (ft_check_quotes(input))
		return(NULL);
	line = ft_modif_line(input);
	return(line);
}

int main(int ac, char **av)
{
	t_def_char *line;
	int i;

	i = 0;
	line = 0;
	if (ac < 2)
		return(0);
	line = ft_parce_input(av[1]);
	if (!line)
		return(0);
	while (line[i].c)
	{
		ft_putchar_fd(line[i].c, 1);
		ft_putstr_fd("  = ",1);
		ft_putnbr_fd(line[i++].quotes, 1);
		write(1, "\n", 1);
	}
}
