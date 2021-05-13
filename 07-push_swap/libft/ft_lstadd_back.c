/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:31:01 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/15 17:44:02 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*current;

	if (lst && *lst)
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else if (lst)
		*lst = new;
}
