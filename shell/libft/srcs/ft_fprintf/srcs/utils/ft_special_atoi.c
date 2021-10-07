/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:51:42 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/30 16:30:58 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_special_atoi(const char *s, int *i)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (ret);
}
