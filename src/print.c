/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:14:33 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/31 11:14:53 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_error(void)
{
	exit(ft_printf("ERROR\n"));
}

void		usage(void)
{
	ft_printf("Usage: ./lem-in [-glwh] [-f filename]\n");
	if (g_data.flags.h == 0)
	{
		ft_printf("		-h help menu;\n");
		exit(1);
	}
	ft_printf("		-g show graph,\n");
	ft_printf("		-l show way counts,\n");
	ft_printf("		-w show all ways,\n");
	ft_printf("		-f read file;\n");
	exit(1);
}

void		print_gnl(t_gnl *rmp)
{
	while (rmp->next)
	{
		if (rmp)
			ft_printf("%s\n", rmp->line);
		rmp = rmp->next;
	}
	ft_printf("\n");
}

void		print_ways_v4(t_ways *waty)
{
	t_way	*t_print;
	t_ways	*tp;

	tp = waty;
	while (tp)
	{
		t_print = tp->way;
		while (t_print->next)
			t_print = t_print->next;
		while (t_print)
		{
			if (t_print->parent)
				ft_printf("\033[1;34m{%s}\033[0m\033[0;32m -> \033[0m",
					t_print->room->name);
			else
				ft_printf("\033[1;34m{%s}\033[0m", t_print->room->name);
			t_print = t_print->parent;
		}
		if (g_data.flags.l)
			ft_printf(" - \033[0;31m%d\033[0m\n\n", tp->op);
		else
			ft_printf("\n\n");
		tp = tp->next;
	}
}

void		print_graph(t_graph *print)
{
	t_conn	*s1;

	while (print)
	{
		s1 = print->conn;
		ft_printf("\033[0;31mRoom - %s\033[0m\n", print->name);
		if (s1)
		{
			ft_printf("\033[0;32m    -> %s \033[0m\n", s1->room->name);
			while (s1->next)
			{
				s1 = s1->next;
				ft_printf("\033[0;32m    -> %s \033[0m\n", s1->room->name);
			}
		}
		print = print->next;
	}
	ft_printf("\n");
}
