/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnastro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:08:46 by gnastro           #+#    #+#             */
/*   Updated: 2021/05/19 17:04:43 by gnastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordcount(const char *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[n])
	{
		while (s[n] == c && s[n] != '\0')
			n++;
		if (s[n] != c && s[n] != '\0')
			i++;
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	return ((int)i);
}

void	ft_putendl(char const *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

static char	*reader(char *store, char **line)
{
	char	*tmp;
	int		n;

	n = 0;
	while (store[n] != '\n' && store[n] != '\0')
		n++;
	*line = ft_strsub(store, 0, n);
	if (store[n] == '\0')
	{
		tmp = NULL;
		free(store);
	}
	else
	{
		tmp = ft_strsub(store, n + 1, ft_strlen(store + n) + 1);
		free(store);
	}
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*store[FD_MAX];
	int				red;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!store[fd])
		store[fd] = ft_strnew(0);
	red = (read(fd, buff, BUFF_SIZE));
	while (!ft_strchr(store[fd], '\n') && (red > 0))
	{
		buff[red] = '\0';
		tmp = ft_strjoin(store[fd], buff);
		ft_strdel(&store[fd]);
		store[fd] = ft_strdup(tmp);
		free(tmp);
	}
	if (red < BUFF_SIZE && !ft_strlen(store[fd]))
		return (0);
	store[fd] = reader(store[fd], line);
	return (1);
}
