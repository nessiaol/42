/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:18:36 by bde-luca          #+#    #+#             */
/*   Updated: 2021/06/17 16:55:28 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	open_file(char  *file_name, char **envp, int flags, int mode)
{
	int		index_position;

	index_position = find_index_position(envp, "PWD=");
}

static void call_father(int *p, char **argv, char **envp)
{
	
}

static void call_child(int *p, char **argv, char **envp)
{
	
}

int	main(int argc, char **argv, char **envp)		//aggiungere char **envp quando serve int argc, char **argv
{
	int		p[2];	//p[0] viene usato per il read e p[1] viene usato per il write, i valori all'interno comunicano la fine del processo indicato.
	pid_t	pid;

	if (argc == 2)
	{
		pid = fork();

		printf("argc: %d argv: %s pid: %d\n", argc, argv[1], pid);
		waitpid(0, p, 0);	//il primo 0 e' il pid child e il secondo zero e' l'exit del processo indicato (child)
		//si puo' mettere anche wait(NULL) che aspetta che tutti i processi child abbiano exit(0) per eseguire il parent.

		if (pid == -1)
		{
			ft_putstr_fd("Fork failed\n", 2);
			return (0);
		}
		if (pid == 0)
			call_child(p, argv, envp);
		else
			call_father(p, argv, envp);
	}
	else
		ft_putstr_fd("Format: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
	return (0);
}
