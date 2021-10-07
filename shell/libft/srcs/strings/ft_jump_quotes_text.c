/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_quotes_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:02:04 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/23 19:26:56 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_jump_quotes_text(char *line, int *i, int dquote)
{
	if (dquote && line[*i] == '"')
	{
		++(*i);
		return ;
	}
	++(*i);
	while (line[*i])
	{
		if (!dquote && line[*i] == '\'')
			break ;
		if (dquote && line[*i] == '"' && !ft_isescaped(line, *i - 1))
			break ;
		++(*i);
	}
	++(*i);
}
