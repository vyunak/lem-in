/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:07:12 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/30 14:22:35 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			valid_room(char *str)
{
	int		tmp[3];

	tmp[0] = -1;
	tmp[1] = 0;
	tmp[2] = 0;
	while (str[++tmp[0]] != '\0')
	{
		if ((str[tmp[0]] == ' ' || str[tmp[0]] == '\t') && tmp[0] == 0)
			return (0);
		if (str[tmp[0]] == ' ' && str[tmp[0] + 1])
			tmp[1]++;
		else if ((str[tmp[0]] == '-' && str[tmp[0] - 1] != ' ') ||
			(str[tmp[0]] == '-' && str[tmp[0] + 1] == ' '))
			tmp[2]++;
		else if ((tmp[1] > 0 && str[tmp[0]] == '-' && str[tmp[0] - 1] != ' '))
			return (0);
		else if (tmp[1] > 0 && str[tmp[0]] != '-' &&
				ft_isdigit(str[tmp[0]]) == 0)
			return (0);
	}
	if (tmp[1] == 2 && tmp[2] == 0)
		return (1);
	if (tmp[1] == 0 && tmp[2] == 1)
		return (2);
	return (0);
}

int			check_al_room(t_graph **s1, char **up)
{
	if ((ft_strcmp((*s1)->x, up[1]) == 0 && ft_strcmp((*s1)->y, up[2]) == 0) ||
		(ft_strcmp((*s1)->name, up[0]) == 0))
		return (1);
	while ((*s1)->next)
	{
		(*s1) = (*s1)->next;
		if ((ft_strcmp((*s1)->x, up[1]) == 0 &&
			ft_strcmp((*s1)->y, up[2]) == 0) ||
			(ft_strcmp((*s1)->name, up[0]) == 0))
			return (1);
	}
	return (0);
}

t_graph		*get_room(char *name)
{
	t_graph	*tmp_2;

	tmp_2 = g_raph;
	while (tmp_2)
	{
		if (ft_strcmp(tmp_2->name, name) == 0)
			return (tmp_2);
		tmp_2 = tmp_2->next;
	}
	return (NULL);
}

void		write_room(t_way **room, t_way *parent, t_conn *conn)
{
	(*room)->next = (t_way*)malloc(sizeof(t_way));
	(*room)->next->next = NULL;
	(*room)->next->room = conn->room;
	(*room)->next->parent = parent;
}

void		write_start(t_way **start)
{
	(*start) = (t_way*)malloc(sizeof(t_way));
	(*start)->next = NULL;
	(*start)->room = g_data.start;
	(*start)->parent = NULL;
}
