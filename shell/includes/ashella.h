#ifndef ASHELLA_H
# define ASHELLA_H

# include "../libft/incs/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>	//forse non serve
# include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>	//per waitpid
# include <fcntl.h>		//per unlink
#include <assert.h>

typedef struct s_pipex
{
	int		bool_pipes;
	char	**cmd_and_flags;
	char	**cmd_and_flags_2;
	// char	*cmd_1;
	// char	*cmd_2;
	// char	*path_cmd_1;
	// char	*path_cmd_2;
	char	**files;
	int		**files_fd;
	char	*buffer_read;
	int		pipe_fd[2];
	short	i;
	short	x;
}			t_pipex;

typedef	struct		s_checks
{
	int		bool_pipes;
	int		input_file;
	int		output_file;
	int		append_file;
	int		delimiter_file;
}					t_checks;

typedef struct		s_files
{
	char 	*filein;
	int		fd_file1;
	char	*fileout;
	int		fd_file2;
	int		saved_stdout;
	int		saved_stdin;
}					t_files;

typedef	struct		s_cmds
{
	char	***cmd_and_flags;
	char	**command;
	char	**cmds_path;
}					t_cmds;

typedef struct		s_cd
{
	char	*tilde_path;
}					t_cd;

typedef struct		s_shell
{
	char		*line;
	char		**splitted_line;
	int			argc;
	t_cd		cd;
	t_pipex		pipex;
	t_cmds		cmds;
	t_checks	checkif;
	t_files		files;
}					t_shell;


t_shell	*g_shell;

char *ft_prompt();

/* utils */
void	ft_print_start_msg(void);
void	ft_init();
int		ft_index_position(char **src, char *to_find);
void	ft_create_tilde_path(char *home);

/* parser */
int		parse_cmd(char **envp);
void	ft_check_specialchars(void);
// void	ft_checkif(char **envp);
void	ft_checkif_files(char **envp);
int		ft_access_file(char *path);
int		ft_check_inputfile(char *str, char **envp);
int		ft_check_outputfile(char *str, char **envp);
int		ft_checkif_cmd(char **envp);

/* cmds */
int		ft_pwd(void);
int		ft_echo(char **av);
int		ft_cd(char **envp);
int		ft_if_cd(char **envp, int arg_check);

/* redirection */

void	ft_redirect_output(void);
void	ft_reset_output(void);

#endif
