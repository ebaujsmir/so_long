# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmirnov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:51:39 by esmirnov          #+#    #+#              #
#    Updated: 2022/04/25 13:51:43 by esmirnov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long\

SRCS		=	so_long.c\
				src/ft_errors_check.c\
				src/ft_print_error.c\
				src/ft_data_free.c\
				src/ft_data_init.c\
				src/ft_map_init.c\
				src/ft_map_read.c\
				src/ft_map_size.c\
				src/ft_map_check.c\
				src/ft_map_draw.c\
				src/ft_img_load.c\
				src/ft_key_hook.c\
				src/ft_move_p.c\
				src/ft_map_pers_position.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Werror -Wextra -g3 -O3

CC			=	cc

INC			=	-Iinclude -Ilibft

LIBFT		=	libft/libft.a

MLX			=	mlx/libmlx.a

GNL			=	gnl/

MINILIBX	=	-Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

RM			=	rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX) 
	$(CC) $(INC) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)

$(LIBFT):
	@make -C libft/

$(MLX):
	@make -C mlx/

#delete .o files
clean: libft_clean
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

libft_clean:
	make clean -C libft/

# delete all and recompile all
re:	fclean
	make all

.PHONY:	all clean libft_clean fclean re
