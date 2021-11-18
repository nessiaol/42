/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:11:18 by dmangola          #+#    #+#             */
/*   Updated: 2021/10/19 15:46:38 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

int	ft_pwd(void)
{
	char	*buf;

	buf = NULL;
	printf("%s\n", getcwd(buf, 300));

	free(buf);
	return (EXIT_SUCCESS);
}