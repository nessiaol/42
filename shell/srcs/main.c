/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:07:46 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/19 19:00:47 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ashella.h"


char *ft_prompt(char **envp)
{
	char *line_read = NULL;
	while(1)
	{
		ft_init();
		/* If the buffer has already been allocated, return the memory to the free pool. */
		if (line_read)
		{
			//printf("ao\n");
			free (line_read);
			line_read = (char *)NULL;
		}
		/* Get a line from the user. */
		g_shell->line = readline("SHellina~ ");
		g_shell->splitted_line = ft_bnessi_split(g_shell->line, ' ');
		parse_cmd(envp);
		if (g_shell->checkif.output_file || g_shell->checkif.append_file)
			ft_reset_output();
		/* If the line has any text in it, save it on the history. */
		if (line_read && *line_read)
			add_history (line_read);
	}
	return (line_read);
}

int	main(int argc, char **av, char **envp)
{
	//printf("prova main\n");
	t_shell		shell;

	g_shell = &shell;
	argc = g_shell->argc;
	ft_strcmp(av[0], "annamaria");
	// char **evv = envp;
	// evv = av;

	//ft_print_start_msg(); DA AGGIUNGERE A PROGETTO FINITO
	//ft_init();
	//printf("prova main2\n");
	shell.line = ft_prompt(envp);
	// if(!evv)
	// 	return 0;

	//deve restare aperto fino a "exit" o ctrl-d
}