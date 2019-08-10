# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 10:31:25 by vyunak            #+#    #+#              #
#    Updated: 2019/07/31 12:09:26 by vyunak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FILE = ants.c flags.c graph.c main_bfs.c print.c room_conn.c room_w.c validation.c ways.c
FILE_P = $(addprefix src/, $(FILE))
OBJ = $(FILE:.c=.o)
OBJ_P = $(addprefix .obj/, $(OBJ))
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = .obj
lib_a = './libft/libft.a'

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(lib_a):
	@make -C libft

$(NAME): $(OBJ_P)
	gcc $(OBJ_P) libft/libft.a $(FLAGS) -o $(NAME)
	@echo "\033[1;37mCompiled!\033[0m";\

$(OBJ_P): $(lib_a) $(OBJ_DIR)
	gcc -o $@ -c $(@:.obj/%.o=src/%.c) -O3

clean:
	@rm -fr $(OBJ_P)
	@make -C libft clean
	@echo "\033[0;32mDone!\033[0m";\

fclean: clean
	@make -C libft fclean
	@rm -fr .obj
	@rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: all re OBJ_DIR clean fclean