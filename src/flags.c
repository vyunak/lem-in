/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:13:22 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/30 14:30:50 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		bonus(int x)
{
	if (g_data.flags.w == 1)
		print_ways_v4(g_w);
	if (g_data.flags.l == 1)
	{
		if (g_data.count)
		{
			x = ft_atoi(ft_strchr(g_data.count, ':') + 1);
			if (g_data.x - x <= 10)
				ft_printf("\033[0;32m%s\033[0m\n", g_data.count);
			else
				ft_printf("\033[0;31m%s\033[0m\n", g_data.count);
		}
		ft_printf("\033[1;34m %s\033[0m \033[0;32m%d\033[0m\n",
			"Way count:", g_data.x);
		(g_data.flags.g) ? ft_printf("\n") : 0;
	}
	if (g_data.flags.g)
	{
		ft_printf("\033[0;32mStart\033[0m - \033[1;33m%s\033[0m\n",
			g_data.start->name);
		ft_printf("\033[0;31mEnd\033[0m - \033[1;33m%s\033[0m\n",
			g_data.end->name);
		(g_data.flags.l) ? ft_printf("%s\033[0m - \033[0;32m%d\033[0m\n",
			"\033[3;37mAnts", g_data.ants) : 0;
	}
}

int			set_flags(char flags)
{
	if (flags == 'h' && g_data.flags.h != 1)
		return ((g_data.flags.h = 1) ? 0 : 0);
	else if (flags == 'w' && g_data.flags.w != 1)
		return (g_data.flags.w = 1);
	else if (flags == 'l' && g_data.flags.l != 1)
		return (g_data.flags.l = 1);
	else if (flags == 'g' && g_data.flags.g != 1)
		return (g_data.flags.g = 1);
	return (0);
}

void		get_file(int ac, char **av)
{
	if (!av[ac + 1])
		usage();
	if ((g_data.flags.f = open(av[ac + 1], 0)) == -1)
		exit(ft_printf("File not found!\n"));
	if (read(g_data.flags.f, NULL, 1) == 0)
		exit(ft_printf("File is empty!\n"));
}

void		indent_flag(char **av, int (*x)[2])
{
	if (av[(*x)[0]][(*x)[1]] == 'f' &&
		(av[(*x)[0]][(*x)[1] + 1] || av[(*x)[0]][(*x)[1] - 1] != '-'))
		usage();
	else if (ft_strchr("lwgh", av[(*x)[0]][(*x)[1]]) != NULL)
	{
		if (set_flags(av[(*x)[0]][(*x)[1]]) == 0)
			usage();
	}
	else if (g_data.flags.f <= 0)
	{
		get_file((*x)[0], av);
		(*x)[1] = 0;
		(*x)[0] += 2;
	}
	else
		usage();
}

void		get_flag(int ac, char **av)
{
	int i[2];

	i[0] = 0;
	while (ac > ++i[0])
	{
		i[1] = 0;
		if (av[i[0]][i[1]] == '-' && av[i[0]][i[1] + 1])
		{
			while (av[i[0]] && av[i[0]][++i[1]])
			{
				if (ft_strchr("lwhfg", av[i[0]][i[1]]) != NULL)
					indent_flag(av, &i);
				else
					usage();
			}
		}
		else
			usage();
	}
}
