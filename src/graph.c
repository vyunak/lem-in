/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:18:12 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/30 14:18:58 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_struct(t_way **str, t_way *way)
{
	(*str) = (t_way*)malloc(sizeof(t_way));
	(*str)->next = NULL;
	(*str)->parent = NULL;
	(*str)->room = way->room;
}

t_graph		*create_graph(char ***str)
{
	char	**strs;

	strs = *str;
	g_raph = (t_graph*)malloc(sizeof(*g_raph));
	g_raph->next = NULL;
	g_raph->prev = NULL;
	g_raph->name = strs[0];
	g_raph->x = strs[1];
	g_raph->y = strs[2];
	g_raph->vis = 1;
	g_raph->conn = NULL;
	return (g_raph);
}

int			add_room_list(char *ln, int st)
{
	char	**up;
	t_graph	*tmp;

	up = ft_strsplit(ln, ' ');
	if (up[0] && up[1] && up[2] && !up[3])
	{
		if (!g_raph)
			tmp = create_graph(&up);
		else
		{
			tmp = g_raph;
			if (check_al_room(&tmp, up) == 1)
				return (ft_free_arr2(&up, 0));
			ct_graph_conn(&tmp, &up);
		}
		(st == 99 && !g_data.start) ? (g_data.start = tmp) : 0;
		(st == -99 && !g_data.end) ? (g_data.end = tmp) : 0;
		free(up);
		return (1);
	}
	return (ft_free_arr2(&up, 0));
}

t_conn		*add_conn_first(t_conn *stc, t_graph *grp)
{
	stc = (t_conn *)malloc(sizeof(*stc));
	stc->room = grp;
	stc->next = NULL;
	stc->prev = NULL;
	return (stc);
}

t_conn		*add_conn_next(t_conn *stc, t_graph *grp)
{
	while (stc->next)
		stc = stc->next;
	stc->next = (t_conn *)malloc(sizeof(*stc));
	stc->next->room = grp;
	stc->next->next = NULL;
	stc->next->prev = stc;
	return (stc);
}
