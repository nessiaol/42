/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:45:19 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/07 16:56:16 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

int	parse_cmd(char **envp)
{
	int i;
	int x;

	i = 0;
	x = 0;
	//ft_init();
	// check per caratteri legati a file e pipes
	ft_check_specialchars();
	//check dei file
	ft_checkif_files(envp);
	ft_checkif_cmd(envp);
	//check dei comandi		DA FARE!!
	// while (g_shell->splitted_line[i] != '\0')
	// {
	// 	//FARGLI SALTARE I CARATTERI SPECIALI < > << >> E I FILE
	// 	ft_checkif_cmd(g_shell->splitted_line[i], envp);
	// 	i++;
	// }
	return(0);
}

int	ft_checkif_cmd(char **envp)
{
	int i;
	int	x;
	char *word;

	i = 0;
	while (g_shell->splitted_line)
	{
		word = g_shell->splitted_line[i];
		if ((ft_strcmp(word, "<")) == 0 || (ft_strcmp(word, ">")) == 0 ||
			(ft_strcmp(word, "<<")) == 0 || (ft_strcmp(word, ">>")) == 0)
			i += 2;
		if (!(ft_strcmp(word, "pwd")))
			if (!(ft_pwd()))
				return(1);
		if (!(ft_strcmp(word, "echo")))
			if (!(ft_echo(g_shell->splitted_line)))
				return(1);
		if (!(ft_strcmp(word, "cd")))
			if (!(ft_cd(envp)))
				return(1);
		if (!(ft_strcmp(word, "env")))
			if (!(ft_env(envp)))
				return(1);
		if (!(ft_search_cmd(g_shell->splitted_line[i], envp)))
		{
			printf("command not found:  %s\n", g_shell->splitted_line[i]);
			return(1);
		}
		x = 0;
		g_shell->cmds.cmd_and_flags = malloc(sizeof((**g_shell->splitted_line) - i));
		while (g_shell->splitted_line[i])
		{
			g_shell->cmds.cmd_and_flags[x] = g_shell->splitted_line[i];
			x++;
			i++;
		}
		g_shell->cmds.cmd_and_flags[x] = NULL;
		if (!execve(g_shell->cmds.path_cmd, g_shell->cmds.cmd_and_flags, envp))
			exit(1);

		// {

		// }
		
	}
	return (1);
}

void	ft_check_specialchars(void)
{
	int i;

	i = 0;
	
	while (g_shell->splitted_line[i] != '\0')
	{
		if ((ft_strcmp(g_shell->splitted_line[i], "|")) == 0)
			g_shell->checkif.bool_pipes = 1;
		else if ((ft_strcmp(g_shell->splitted_line[i], "<<")) == 0)
		{
			g_shell->checkif.delimiter_file = 1;
			g_shell->files.filein = g_shell->splitted_line[i + 1];
		}
		else if ((ft_strcmp(g_shell->splitted_line[i], "<")) == 0)
		{
			g_shell->checkif.input_file = 1;
			g_shell->files.filein = g_shell->splitted_line[i + 1];
		}
		else if ((ft_strcmp(g_shell->splitted_line[i], ">")) == 0)
		{
			g_shell->checkif.output_file = 1;
			g_shell->files.fileout = g_shell->splitted_line[i + 1];
			//ft_redrirect_output();
		}
		else if ((ft_strcmp(g_shell->splitted_line[i], ">>")) == 0)
		{
			g_shell->checkif.append_file = 1;
			g_shell->files.fileout = g_shell->splitted_line[i + 1];
		}
		i++;
	}
}