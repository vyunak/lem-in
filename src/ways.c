/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:19:18 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/30 14:21:29 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_deep_way(t_way *way)
{
	t_way *tmp;

	tmp = way;
	while (tmp)
	{
		if (tmp->room->name != g_data.end->name &&
			tmp->room->name != g_data.start->name)
			tmp->room->vis = 5;
		tmp = tmp->parent;
	}
}

t_way		*swap_way_v3(t_way *rls)
{
	t_way *way;
	t_way *new_way;
	t_way *tmp_way;

	new_way = NULL;
	way = rls;
	while (way)
	{
		if (!new_way)
			create_struct(&new_way, way);
		else
		{
			tmp_way = new_way;
			while (tmp_way->next)
				tmp_way = tmp_way->next;
			tmp_way->next = (t_way*)malloc(sizeof(t_way));
			tmp_way->next->next = NULL;
			tmp_way->next->room = way->room;
			tmp_way->next->parent = tmp_way;
		}
		way = way->parent;
	}
	return (new_way);
}

void		write_way(t_way *way)
{
	t_ways	*tm;
	t_way	*tms;

	g_data.itr = 0;
	set_deep_way(way);
	tms = way;
	while (++g_data.itr > 0 && tms)
		tms = tms->parent;
	if (!g_w)
	{
		g_w = (t_ways*)malloc(sizeof(*g_w));
		g_w->way = swap_way_v3(way);
		g_w->next = 0;
		g_w->op = g_data.itr - 1;
	}
	else
	{
		tm = g_w;
		while (tm->next)
			tm = tm->next;
		tm->next = (t_ways*)malloc(sizeof(*g_w));
		tm->next->way = swap_way_v3(way);
		tm->next->op = g_data.itr - 1;
		tm->next->next = NULL;
	}
}

int			free_w_ways(t_way **way, int ret)
{
	t_way *tmp;
	t_way *tmps;

	tmp = NULL;
	tmps = *way;
	while (tmps)
	{
		if (tmp)
			free(tmp);
		tmp = tmps;
		tmps = tmps->next;
	}
	free(tmp);
	(*way) = NULL;
	return (ret);
}

int			way_to(t_way **w_e, t_conn *conn)
{
	while ((*w_e)->next)
	{
		if (conn->room->name != g_data.end->name &&
			conn->room->name != g_data.start->name)
			if ((*w_e)->room->name == conn->room->name)
				return (0);
		if (conn->room->vis == 5)
			return (0);
		(*w_e) = (*w_e)->next;
	}
	if (conn->room->name != g_data.end->name &&
		conn->room->name != g_data.start->name)
		if ((*w_e)->room->name == conn->room->name)
			return (0);
	return (1);
}
