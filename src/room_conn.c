/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_conn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:09:17 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/30 14:24:05 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			add_connect(t_graph *s1, t_graph *s2)
{
	if (s1->conn == NULL)
		s1->conn = add_conn_first(s1->conn, s2);
	else
	{
		if (check_al_conn(s1->conn, s2) == 0)
			return (0);
		add_conn_next(s1->conn, s2);
	}
	if (s2->conn == NULL)
		s2->conn = add_conn_first(s2->conn, s1);
	else
	{
		if (check_al_conn(s2->conn, s1) == 0)
			return (0);
		add_conn_next(s2->conn, s1);
	}
	return (1);
}

int			add_conn(char *str)
{
	char	**up;
	t_graph	*tmp;
	t_graph	*tmp_2;

	tmp = g_raph;
	up = ft_strsplit(str, '-');
	if (up[0] && up[1] && ft_strcmp(up[0], up[1]) == 0)
		return (ft_free_arr2(&up, 0));
	if (up[0] && up[1] && !up[2])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, up[0]) == 0)
			{
				g_data.ad_con = 1;
				if ((tmp_2 = get_room(up[1])) && add_connect(tmp, tmp_2) == 1)
					return (ft_free_arr2(&up, 1));
				else
					return (ft_free_arr2(&up, 0));
			}
			tmp = tmp->next;
		}
		return (ft_free_arr2(&up, (g_data.ad_con == 1) ? 1 : 0));
	}
	return (ft_free_arr2(&up, 0));
}

int			check_conn(t_conn *conn, t_way *end, t_way *main, t_way *ways)
{
	while (conn)
	{
		end = ways;
		if (way_to(&end, conn))
			write_room(&end, main, conn);
		(conn->room->name == g_data.end->name) ?
			write_way(end->next) : 0;
		if (conn->room->name == g_data.end->name)
			return (free_w_ways(&ways, 1));
		conn = conn->next;
	}
	return (0);
}

int			check_al_conn(t_conn *tm, t_graph *s)
{
	t_conn	*tmp;

	tmp = tm;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, s->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ct_graph_conn(t_graph **s1, char ***up)
{
	char	**ups;

	ups = *up;
	(*s1)->next = (t_graph*)malloc(sizeof(*g_raph));
	(*s1)->next->prev = (*s1);
	(*s1) = (*s1)->next;
	(*s1)->next = NULL;
	(*s1)->vis = 1;
	(*s1)->conn = NULL;
	(*s1)->name = ups[0];
	(*s1)->x = ups[1];
	(*s1)->y = ups[2];
}
