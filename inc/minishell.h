/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:46:20 by equesnel          #+#    #+#             */
/*   Updated: 2022/08/03 00:33:09 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"

typedef struct s_def_char
{
	char c;
	char quotes;
	char bool_m;
}		t_def_char;

char	ft_check_meta(char	c);
t_def_char      **ft_split_cmd(t_def_char *line);

#endif
