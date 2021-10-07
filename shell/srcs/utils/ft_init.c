/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:45:19 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/12 17:28:36 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

void	ft_init(void)
{
	// home = "\0";
	// oldpwd = "\0";
	g_shell->checkif.append_file = 0;
	g_shell->checkif.bool_pipes = 0;
	g_shell->checkif.input_file = 0;
	g_shell->checkif.output_file = 0;
	g_shell->checkif.delimiter_file = 0;
}

void	ft_create_tilde_path(char *home)
{
	char	*tmp;
	char	*removed_tilde_path;
	char	*first_copy;
	short	i;

	i = 0;
	first_copy = malloc(sizeof(char *) * ft_strlen(g_shell->splitted_line[i]));
	while (g_shell->splitted_line[1][i])
	{
		if(g_shell->splitted_line[1][i] == '~')
		{
			i++;
			//first_copy[i] = g_shell->splitted_line[1][i];
			ft_strcpy(first_copy, g_shell->splitted_line[1]);
		}
		first_copy[i] = g_shell->splitted_line[1][i];
		i++;
	}
	//ft_putstr_fd(first_copy, 1);
	free(first_copy);
	tmp = ft_strjoin(home, "/");
	removed_tilde_path = ft_strjoin(tmp, first_copy);
	ft_putstr_fd(removed_tilde_path, 1);
}