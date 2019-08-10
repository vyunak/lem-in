/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:23:34 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/31 12:32:47 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			coef(t_ways *rls, int *i)
{
	t_ways	*tmp;
	t_ways	*w_tmp;
	int		x;

	tmp = rls;
	while (tmp)
	{
		x = 0;
		if (tmp != rls)
		{
			w_tmp = tmp;
			while (w_tmp->prev)
			{
				x += tmp->op - w_tmp->prev->op;
				w_tmp = w_tmp->prev;
			}
		}
		(x < (*i)) ? tmp->p = 1 : 0;
		if (x < (*i))
			(*i)--;
		else
			tmp->p = 0;
		tmp = tmp->next;
	}
}

void			go_all_ants_to_end(void)
{
	int		x;

	x = 0;
	while (++x <= g_data.ants)
		ft_printf("L%d-%s ", x, g_data.end->name);
	ft_printf("\n");
	if (g_data.flags.w || g_data.flags.l || g_data.flags.g)
		ft_printf("\n");
}

int				bfs(int i)
{
	t_way	*w_main;
	t_way	*w_end;
	t_conn	*w_conn;
	t_way	*w_ways;

	i++;
	w_end = NULL;
	write_start(&w_ways);
	if (check_start_in_end(&w_ways))
		return (free_w_ways(&w_ways, 0));
	w_main = w_ways;
	while (w_main)
	{
		w_conn = w_main->room->conn;
		if (w_main->room->name != g_data.end->name &&
			w_main->room->vis != 5)
			if (check_conn(w_conn, w_end, w_main, w_ways))
				return (1);
		w_main = w_main->next;
	}
	return (free_w_ways(&w_ways, 0));
}

static void		go_search(void)
{
	int	x;

	x = 0;
	if (!g_data.start || !g_data.end ||
		!g_data.start->conn || !g_data.end->conn)
		print_error();
	while (bfs(x))
		x++;
	if ((x > 0 || g_data.st_en == 1) && g_data.flags.g == 1)
		print_graph(g_raph);
	else if (x > 0 || g_data.st_en == 1)
		print_gnl(g_gnl);
	if (x > 0)
		go_ants();
	else if (g_data.st_en == 1)
		go_all_ants_to_end();
	else if (g_data.st_en == 0)
		print_error();
	bonus(x);
}

int				main(int ac, char **av)
{
	t_gnl	*tmp;

	get_flag(ac, av);
	g_gnl = (t_gnl *)malloc(sizeof(*g_gnl));
	tmp = g_gnl;
	while (get_next_line((g_data.flags.f > 0) ?
		g_data.flags.f : 0, &tmp->line) > 0)
	{
		if (tmp->line[0] != '#' && g_data.lvl == 0)
			get_ant(tmp->line);
		else if (tmp->line[0] != '#')
			factor_list(valid_room(tmp->line), tmp->line);
		else if (tmp->line[0] == '#' &&
				tmp->line[1] == '#' && tmp->line[2] != '#')
			get_command(tmp->line);
		else if (g_data.lvl == 1 && tmp->line[0] == '#' &&
				tmp->line[1] != '#' && ft_strstr(tmp->line,
					"Here is the number of lines required:") != NULL)
			g_data.count = tmp->line;
		tmp->next = (t_gnl *)malloc(sizeof(*g_gnl));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	go_search();
	return (0);
}
