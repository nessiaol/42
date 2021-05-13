/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:18:42 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/05 18:18:44 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stdin_gnl(char **line)
{
	char	buffer[512];
	int		reader;
	int		i;

	i = 0;
	if (read(0, &buffer[0], 0) < 0 || (!line))
		return (-1);
	reader = read(0, &buffer[i], 1);
	while (reader > 0 && buffer[i] != '\n')
		i++;
	buffer[i] = '\0';
	*line = malloc(i + sizeof(char));
	i = -1;
	if (reader != -1 && (*line))
	{
		while (buffer[++i])
			(*line)[i] = buffer[i];
		(*line)[i] = '\0';
	}
	if (reader > 0)
		reader = 1;
	return (reader);
}
