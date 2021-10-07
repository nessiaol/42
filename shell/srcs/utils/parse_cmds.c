
#include "../../includes/ashella.h"

static void	ft_free_str0(char *bf_pt, char **spl_pt)
{
	g_shell->cmds.x = 0;
	g_shell->cmds.path_cmd = strdup(bf_pt);
	while (spl_pt[g_shell->cmds.x])
	{
		free(spl_pt[g_shell->cmds.x]);
		g_shell->cmds.x++;
	}
	free(spl_pt);
	free(bf_pt);
}

static void	ft_free_str1(char *bf_pt, char **spl_pt)
{
	g_shell->cmds.i = 0;
	free(bf_pt);
	while (spl_pt[g_shell->cmds.i])
	{
		free(spl_pt[g_shell->cmds.i]);
		g_shell->cmds.i++;
	}
	free(spl_pt);
}

int	ft_search_cmd(char *word, char **envp)
{
	char	*path;
	char	**splitted_paths;
	char	*buffer_tmp;
	char	*buffer_path;

	g_shell->cmds.cmd = word;
	buffer_path = NULL;
	path = envp[ft_index_position(envp, "PATH=")] + 5;
	splitted_paths = ft_bnessi_split(path, ':');
	g_shell->cmds.i = 0;
	while (splitted_paths[g_shell->cmds.i])
	{
		buffer_tmp = ft_strjoin(splitted_paths[g_shell->cmds.i], "/");
		if (buffer_path)
			free(buffer_path);
		buffer_path = ft_strjoin(buffer_tmp, g_shell->cmds.cmd);
		free(buffer_tmp);
		if (access(buffer_path, X_OK) != -1)
		{
			ft_free_str0(buffer_path, splitted_paths);
			return (1);
		}
		g_shell->cmds.i++;
	}
	ft_free_str1(buffer_path, splitted_paths);
	return (0);
}
