/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:40:42 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/31 10:09:15 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

typedef	struct		s_gnl
{
	char			*line;
	struct s_gnl	*next;
}					t_gnl;

typedef	struct		s_graph
{
	char			*name;
	char			*x;
	char			*y;
	struct s_conn	*conn;
	struct s_graph	*prev;
	struct s_graph	*next;
	short			vis;
}					t_graph;

typedef	struct		s_conn
{
	int				p;
	struct s_graph	*room;
	struct s_conn	*prev;
	struct s_conn	*next;
}					t_conn;

typedef	struct		s_way
{
	short			vis;
	int				name;
	t_graph			*room;
	struct s_way	*parent;
	struct s_way	*next;
}					t_way;

typedef	struct		s_ways
{
	struct s_way	*way;
	int				op;
	short			p;
	struct s_ways	*next;
	struct s_ways	*prev;
}					t_ways;

typedef	struct		s_rlist
{
	struct s_ways	*room;
	short			p;
	struct s_rlist	*next;
}					t_rlist;

typedef	struct		s_flag
{
	short			g;
	short			l;
	short			h;
	short			w;
	short			f;
}					t_flag;

typedef	struct		s_data
{
	int				ants;
	short			lvl;
	short			stat;
	int				i;
	short			x;
	short			st_en;
	short			itr;
	short			ad_con;
	t_graph			*start;
	t_graph			*end;
	t_way			*way;
	char			*count;
	t_flag			flags;
}					t_data;

t_gnl				*g_gnl;
t_data				g_data;
t_graph				*g_raph;
t_ways				*g_w;
t_ways				*g_lway;
t_rlist				*g_rlist;

int					valid_room(char *str);
int					check_al_room(t_graph **s1, char **up);
t_graph				*get_room(char *name);
void				write_room(t_way **room, t_way *parent, t_conn *conn);
int					add_connect(t_graph *s1, t_graph *s2);
int					add_conn(char *str);
int					check_conn(t_conn *conn, t_way *end,
	t_way *main, t_way *ways);
int					check_al_conn(t_conn *tm, t_graph *s);
void				ct_graph_conn(t_graph **s1, char ***up);
void				get_ant(char *str);
void				factor_list(int i, char *str);
void				get_command(char *str);
int					check_start_in_end(t_way **ways);
void				bonus(int x);
int					set_flags(char flags);
void				get_file(int ac, char **av);
void				indent_flag(char **av, int (*x)[2]);
void				get_flag(int ac, char **av);
void				usage(void);
void				print_gnl(t_gnl *rmp);
void				print_ways_v4(t_ways *waty);
void				print_graph(t_graph *print);
void				create_struct(t_way **str, t_way *way);
t_graph				*create_graph(char ***str);
int					add_room_list(char *ln, int st);
t_conn				*add_conn_first(t_conn *stc, t_graph *grp);
t_conn				*add_conn_next(t_conn *stc, t_graph *grp);
void				set_deep_way(t_way *way);
t_way				*swap_way_v3(t_way *rls);
void				write_way(t_way *way);
int					free_w_ways(t_way **way, int ret);
int					way_to(t_way **w_e, t_conn *conn);
void				write_start(t_way **start);
void				coef(t_ways *rls, int *i);
void				go_all_ants_to_end(void);
int					bfs(int i);
void				set_deep_way(t_way *way);
t_way				*swap_way_v3(t_way *rls);
void				write_way(t_way *way);
int					free_w_ways(t_way **way, int ret);
int					way_to(t_way **w_e, t_conn *conn);
int					ft_free_arr2(char ***str, int ret);
void				push_ants(t_ways *ways, int *name);
void				run_ants(t_ways *tm_way, int *ants);
void				gogo_v2(t_ways *ways);
void				go_ants(void);
void				print_error(void);

#endif
