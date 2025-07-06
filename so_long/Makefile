# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 13:57:57 by hanjkim           #+#    #+#              #
#    Updated: 2024/09/25 13:22:56 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    	=	so_long

CC			=	cc

CFLAGS  	=	-Wall -Werror -Wextra -g

LIBFT_DIR	=	libft/
PRINTF_DIR	=	ft_printf/

LIBFT   	=	$(LIBFT_DIR)libft.a
PRINTF		=	$(PRINTF_DIR)libftprintf.a

SRC_DIR 	=	sources/game_logic
SRCS     	=	$(SRC_DIR)/end_game.c			\
				$(SRC_DIR)/flood_fill.c			\
				$(SRC_DIR)/utils.c				\
				$(SRC_DIR)/image_init.c			\
				$(SRC_DIR)/map_check_1.c		\
				$(SRC_DIR)/map_check_2.c		\
				$(SRC_DIR)/movement.c			\
				$(SRC_DIR)/read_map.c			\
				$(SRC_DIR)/so_long.c			\
				$(SRC_DIR)/so_long_strjoin.c	\
				$(SRC_DIR)/window_init.c		\

OBJS     	=	$(SRCS:%.c=%.o) 

RM			=	rm -rf

LINK_FLAGS	=	-L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf
MLXFLAGS	=	-lmlx -lXext -lX11 -lm

all:		$(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(PRINTF):
		@make -C $(PRINTF_DIR)

$(NAME):	$(OBJS) $(LIBFT) $(PRINTF)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LINK_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean

re: 		fclean all

.PHONY: 	all clean fclean re
