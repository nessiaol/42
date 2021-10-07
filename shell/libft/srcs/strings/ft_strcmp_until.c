/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:46:47 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/23 12:05:04 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_until_inc(const char *s1, const char *s2, int c)
{
	long	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i + 1] != c && s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}

int	ft_strcmp_until_exc(const char *s1, const char *s2, int c)
{
	long	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i] != c && s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}
