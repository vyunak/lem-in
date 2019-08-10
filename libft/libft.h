/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:44:09 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:48:07 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# define BUFF_SIZE 100
# define HH 1
# define H 2
# define Z 3
# define L 4
# define LL 5
# define J 6
# define FL 7
# define LLI 9223372036854775807

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_main
{
	int				hash;
	int				minus;
	int				fminus;
	int				plus;
	int				space;
	int				zero;
	int				width;
	int				rigor;
	int				castm;
	int				type;
	int				usub;
}					t_main;

typedef struct		s_sp
{
	int				start;
	int				end;
	int				zero;
	char			*prefix;
}					t_sp;

int					printf_putchar(int c);
int					printf_putstr(char const *s);
int					ft_printf(char *format, ...);
t_main				set_tm(void);
t_sp				set_space(void);
void				set_flag(t_main *tm, char flag);
int					istype(char c);
int					iscastm(char c);
int					isflag(char c);
int					set_castm(const char *format, t_main *tm, int *i);
size_t				ft_strlen(const char *s);
int					type_c(va_list args, t_main tm);
int					print_c(t_main tm, int c);
int					f_odd(char *n1, char *n2, t_main str);
int					type_f(va_list args, t_main str);
char				*f_sin(long double nbr, int i, int count, char **buff);
int					ft_str(char const *s, int rigor);
char				*ft_uitoa(__uint128_t number);
int					type_s(va_list args, t_main tm);
int					type_int(va_list args, t_main tm);
char				*ft_itoa_max(intmax_t number);
int					type_unsigned(va_list args, t_main tm);
char				*ft_itoa_base(uintmax_t nbr, int base_t, int der);
int					type_o(va_list args, t_main tm);
int					type_x(va_list args, t_main tm);

int					get_next_line(const int fd, char **line);

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int nbr);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_get_size(int c);
void				ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **ap);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hs, const char *nd, size_t len);
char				*ft_strrchr(const char *str, int c);
void				ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
