/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:10:46 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/31 12:36:02 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_ant(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) == 0)
			print_error();
	if (i > 8 || i == 0 || str[0] == '0')
		print_error();
	g_data.ants = ft_atoi(str);
	g_data.lvl = 1;
	if (g_data.stat != 0)
		print_error();
}

void		factor_list(int i, char *str)
{
	if (i == 0 || str[0] == 'L')
		print_error();
	else if (i == 1)
	{
		if (add_room_list(str, g_data.stat) == 0)
			print_error();
		g_data.stat = 0;
	}
	else if (i == 2)
	{
		if (add_conn(str) == 0)
			print_error();
	}
}

void		get_command(char *str)
{
	if (ft_strcmp("##start", str) == 0)
	{
		if (g_data.stat != 99 && g_data.stat != -99 && !g_data.start)
			g_data.stat = 99;
		else
			print_error();
	}
	else if (ft_strcmp("##end", str) == 0)
	{
		if (g_data.stat != -99 && g_data.stat != 99 && !g_data.end)
			g_data.stat = -99;
		else
			print_error();
	}
	else if (g_data.stat == -99 || g_data.stat == 99)
		print_error();
}

int			check_start_in_end(t_way **ways)
{
	t_conn *conn;

	conn = (*ways)->room->conn;
	while (conn)
	{
		if (conn->room->name == g_data.end->name)
		{
			(*ways)->next = (t_way*)malloc(sizeof(t_way));
			(*ways)->next->next = NULL;
			(*ways)->next->parent = (*ways);
			(*ways)->next->room = g_data.end;
			write_way((*ways)->next);
			g_data.st_en = 1;
			g_data.x = 1;
			return (1);
		}
		conn = conn->next;
	}
	return (0);
}
