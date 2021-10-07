/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:45:19 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/05 15:53:35 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

void	ft_checkif_files(char **envp)
{
	if (g_shell->checkif.input_file || g_shell->checkif.delimiter_file)
		ft_check_inputfile(g_shell->files.filein, envp);		//controlla se è un file valido
	if (g_shell->checkif.output_file || g_shell->checkif.append_file)
		ft_check_outputfile(g_shell->files.fileout, envp);		//controlla se è valido e se non esiste lo crea
	//printf("prova dopo check dei files\n");
}

int	ft_access_file(char *path)
{
	if (access(path, F_OK) == -1)
		ft_putstr_fd("open: no such file or directory\n", 2);
	else if (access(path, R_OK) == -1)
		ft_putstr_fd("open: READ permission denied\n", 2);
	else if (access(path, W_OK) == -1)
		ft_putstr_fd("open: WRITE permission denied\n", 2);
	else
		return (1);
	return (0);
}

int	ft_check_inputfile(char *str, char **envp)
{
	char	*path;
	char	*buffer_tmp;
	char	*buffer_path;
	int 	i;

	i = 0;
	path = envp[ft_index_position(envp, "PWD=")] + 4;
	buffer_tmp = ft_strjoin(path, "/");
	buffer_path = ft_strjoin(buffer_tmp, str);
	free(buffer_tmp);
	if (ft_access_file(buffer_path) > 0)
	{
		free(buffer_path);
		return (1);
	}
	free(buffer_path);
	return (0);
}

int	ft_check_outputfile(char *str, char **envp)
{
	char	*path;
	char	*buffer_tmp;
	char	*buffer_path;

	path = envp[ft_index_position(envp, "PWD=")] + 4;
	buffer_tmp = ft_strjoin(path, "/");
	buffer_path = ft_strjoin(buffer_tmp, str);
	free(buffer_tmp);
	g_shell->files.fd_file2 = open(str, O_CREAT, 00777);
	if (ft_access_file(buffer_path) > 0)
	{
		free(buffer_path);
		g_shell->files.saved_stdout = dup(1);			//salva la stdout per dopo resettarlo
		close(g_shell->files.fd_file2);					
		g_shell->files.fd_file2 = open(g_shell->files.fileout, O_RDWR);
		dup2(g_shell->files.fd_file2, 1);				//mette le stdout su file di output
		return (1);
	}
	free(buffer_path);
	return (0);
}
