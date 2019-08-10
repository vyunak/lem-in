/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:20:54 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/31 12:34:39 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_free_arr2(char ***str, int ret)
{
	char	**st;
	int		i;

	i = -1;
	if (str && *str)
	{
		st = *str;
		while (st[++i])
			free(st[i]);
		free(st);
	}
	return (ret);
}

void		push_ants(t_ways *ways, int *name)
{
	t_way	*st;

	while (ways)
	{
		if ((*name) <= g_data.ants && ways->p == 1)
		{
			st = ways->way;
			while (st->next)
				st = st->next;
			if (st->parent)
			{
				st->parent->vis = 6;
				st->parent->name = (*name)++;
			}
		}
		ways = ways->next;
	}
}

void		run_ants(t_ways *tm_way, int *ants)
{
	t_way	*st;

	while (tm_way)
	{
		st = tm_way->way;
		while (st)
		{
			if (st->vis == 6)
			{
				if (st->room->name == g_data.end->name)
					(*ants)++;
				if (st->parent)
				{
					st->parent->vis = 6;
					st->parent->name = st->name;
				}
				ft_printf("L%d-%s ", st->name, st->room->name);
				st->vis = 5;
				st->name = 0;
			}
			st = st->next;
		}
		tm_way = tm_way->next;
	}
}

void		gogo_v2(t_ways *ways)
{
	t_ways	*tm_way;
	int		ants;
	int		tmp;
	int		name;

	ants = 0;
	name = 1;
	tmp = g_data.ants;
	g_data.x = 0;
	while (ants < g_data.ants)
	{
		tm_way = ways;
		if (name <= g_data.ants)
			coef(tm_way, &tmp);
		push_ants(tm_way, &name);
		run_ants(tm_way, &ants);
		g_data.x++;
		if (g_data.ants != ants || g_data.flags.w ||
			g_data.flags.l || g_data.flags.g)
			ft_printf("\n");
	}
}

void		go_ants(void)
{
	t_ways *rlist;
	t_ways *prev;

	rlist = g_w;
	while (rlist)
	{
		rlist->prev = NULL;
		if (prev)
			rlist->prev = prev;
		prev = rlist;
		rlist = rlist->next;
	}
	g_w->prev = NULL;
	gogo_v2(g_w);
	ft_printf("\n");
}
