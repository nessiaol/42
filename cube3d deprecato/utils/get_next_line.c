/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:08:55 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/02 18:37:20 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*joinbuffer(char *current, char *buf)
{
	char	*temp;

	if (!current)
		current = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(current, buf);
		free(current);
		current = ft_strdup(temp);
		free(temp);
	}
	return (current);
}

char	*get_newline(char *current, char **line, int read_res)
{
	size_t		i;
	char		*temp;

	i = 0;
	while (current[i])
	{
		if (current[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(current))
	{
		*line = ft_substr_get(current, 0, i);
		temp = ft_substr_get(current, i + 1, ft_strlen(current));
		free(current);
		current = ft_strdup(temp);
		free(temp);
	}
	else if (read_res == 0)
	{
		*line = current;
		current = NULL;
	}
	return (current);
}

int		get_next_line(int fd, char **line)
{
	static char		*current;
	char			buf[BUFFER_SIZE + 1];
	int				read_res;

	if (fd < 0)
		return (-1);
	while ((read_res = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_res == -1)
			return (-1);
		buf[read_res] = '\0';
		current = joinbuffer(current, buf);
		if (ft_strchr_get(buf, '\n'))
			break ;
	}
	if (read_res <= 0 && !current)
	{
		*line = ft_strdup("");
		return (read_res);
	}
	current = get_newline(current, line, read_res);
	if (read_res <= 0 && !current)
		return (read_res);
	return (1);
}
