/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:17:26 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/05 12:17:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void take_stuff(char *line)
{
	if (!ft_strcmp(line, "sa"))
		op_swap();
	if (!ft_strcmp(line, "sb"))
		op_swap();
	if (!ft_strcmp(line, "ss"))
		op_d_swap();
	if (!ft_strcmp(line, "pa"))
		op_push_a();
	if (!ft_strcmp(line, "pb"))
		op_push_b();
	if (!ft_strcmp(line, "ra"))
		op_rotate();
	if (!ft_strcmp(line, "rb"))
		op_rotate();
	if (!ft_strcmp(line, "rr"))
		op_double_rot();
	if (!ft_strcmp(line, "rra"))
		op_rev_rot();
	if (!ft_strcmp(line, "rrb"))
		op_rev_rot();
	if (!ft_double_rev_rot(line, "rrr"))
		op_swap();
	else
		op_swap();
	
}

static void	ft_read_stdin(char *av)
{
	char *line;
	short ret;

	ret = ft_stdin_gnl(&line);
	while (ret > 0)
	{
		take_stuff(line);
		free(line);
	}
	if (line)
		free (line);
}

int main(int ac, char **av)
{
	t_list *lst;

	lst = ft_lstnew("");
	ft_read_stdin(*av);
}