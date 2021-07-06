/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:18:36 by bde-luca          #+#    #+#             */
/*   Updated: 2021/07/06 19:35:21 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void ft_call_father(char **argv, t_data *data)
{
	int		n;					//byte letti in read
	char	line[MAXLINE];		//buffer per lettura

	// waitpid(0, data->pipe_fd, 0);	//il primo 0 e' il pid child e il secondo zero e' l'exit del processo indicato (child)
		//si puo' mettere anche wait(NULL) che aspetta che tutti i processi child abbiano exit(0) per eseguire il parent.
	close(data->pipe_fd[1]);	//chiude la scrittura
	n = read(data->pipe_fd[0], line, MAXLINE);		//legge dall'estremo di lettura della pipe
	write(STDOUT_FILENO, line, n);		//scrive in output quello che legge dalla pipe
	printf("father programma: %s\n", argv[0]);
	// open_file(data->file_2, envp, O_RDWR | O_CREAT | O_TRUNC, 777);
}

void ft_call_child(char **argv, t_data *data)
{
	close(data->pipe_fd[0]);	//chiude la lettura
	write(data->pipe_fd[1], "hello world\n", 12);	//scrive sull'estremo di scrittura della pipe
	printf("child programma: %s\n", argv[0]);
	// open_file(data->file_1, envp, O_RDONLY, 0);
}

int	main(int argc, char **argv, char **envp)		//aggiungere char **envp quando serve int argc, char **argv
{
	pid_t	pid;
	t_data	data;

	if (argc == 5)
	{
		ft_parse_cmd_1(&data, argv, envp);
		ft_parse_cmd_2(&data, argv, envp);
		ft_checkfile_1(&data, argv, envp);
		ft_checkfile_2(&data, argv, envp);

		if (pipe(data.pipe_fd) < 0)		//CREA LA PIPE
		{
			perror("pipe\n");
			exit(1);
		}
		if ((pid = fork()) < 0)		//CREA PARENT/CHILD CON FORK
		{
			perror("fork\n");
			exit(1);
		}

		printf("argc: %d argv: %s pid: %d\n", argc, argv[1], pid);
		waitpid(0, data.pipe_fd, 0);	//il primo 0 e' il pid child e il secondo zero e' l'exit del processo indicato (child)
		//si puo' mettere anche wait(NULL) che aspetta che tutti i processi child abbiano exit(0) per eseguire il parent.

		if (pid == 0)
			ft_call_child(argv, &data);	//dopo aggiungere envp
		else
			ft_call_father(argv, &data);	//dopo aggiungere envp
	}
	else
		ft_putstr_fd("Format: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
	return (0);
}
