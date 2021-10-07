/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:45:19 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/05 15:46:27 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"



void	ft_redirect_output(void)
{
	g_shell->files.saved_stdout = dup(1);
	g_shell->files.fd_file2 = open(g_shell->files.fileout, O_RDWR);
	//close(g_shell->pipe_fd[1][0]);	
	//close(g_shell->pipe_fd[1][1]);
	dup2(g_shell->files.fd_file2, 1);
	//printf("prova in file\n");
	// close(g_shell->pipe_fd[0][0]);
	// if (!execve(g_shell->path_cmd, g_shell->cmd_and_flags, envp))
	// 	exit(1);
}

void	ft_reset_output(void)
{
	dup2(g_shell->files.saved_stdout, 1);
	close(g_shell->files.saved_stdout);
}