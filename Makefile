# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:40:32 by phanosek          #+#    #+#              #
#    Updated: 2023/10/25 20:01:19 by phanosek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#SOURCES
SRCS_DIR = ./SRCS/
SRCS = 	SRCS/main.c \
		SRCS/INITIALIZATION/map_create.c \
		SRCS/ERROR_HANDLING/read_map.c \
		SRCS/ERROR_HANDLING/valid_path.c \
		SRCS/ERROR_HANDLING/check_map.c \
		SRCS/ERROR_HANDLING/error_message.c \
		SRCS/EVENTS+GRAPHICS/render.c \
		SRCS/EVENTS+GRAPHICS/game_utils.c \
		SRCS/EVENTS+GRAPHICS/movements.c \
		SRCS/EVENTS+GRAPHICS/event_handling.c \
		
OBJS = $(SRCS:.c=.o)

#GNL INCLUDE
GNL_DIR = ./GNL/
GNL = ./GNL/get_next_line.h
GNL_SRCS = 	GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		
GNL_OBJS = $(GNL_SRCS:.c=.o)

#LIBFT INCLUDE
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
LIBFT_CREATE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

#MINILIBX INCLUDE
MLX_DIR = minilibx-linux
MLX_CREATE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

#COMPILE
CC = clang
STANDARD_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
INCLUDE_FLAGS := -I ./INCLUDES
LIBRARY_FLAGS := -L $(LIBFT_DIR) -lft

#COLOURS
COLOR_GREEN = "\033[0;32m"
COLOR_RED = "\033[0;31m"
COLOR_BLUE = "\033[0;34m"
COLOR_END = "\033[0m"

#OTHER
NAME = so_long
RM = rm -rf

#RULES

all: ${NAME} ${LIBFT}

${NAME}: $(OBJS) $(GNL_OBJS)
	@make -C ${LIBFT_DIR}
	@echo $(COLOR_GREEN) "LIBFT COMPILED" $(COLOR_END)
	@make -C ${MLX_DIR}
	@echo $(COLOR_GREEN) "MLX COMPILED" $(COLOR_GREEN)
	@echo $(COLOR_BLUE) "COMPILING $@" $(COLOR_END)
	@$(CC) ${SRCS} ${GNL_SRCS} ${LIBFT} $(STANDARD_FLAGS) $(MLX_FLAGS) $(IFLAGS) $(LFLAGS) -o $(NAME)
	@echo $(COLOR_GREEN) "SUCCESSFULLY COMPILED" $(COLOR_END)

clean: 
	@echo $(COLOR_BLUE) "CLEANING" $(COLOR_END)
	@${RM} ${OBJS}
	@${RM} ${OBJ}
	@make clean -C ${LIBFT_DIR} -f ${LIBFT_CREATE} 
	@echo $(COLOR_GREEN)"CLEANING DONE" $(COLOR_END)

fclean: clean
	@echo $(COLOR_BLUE) "FCLEANING" $(COLOR_END)
	@${RM} ${OBJS} ${NAME}
	@echo $(COLOR_GREEN) "${NAME} WAS DELETED." ${COLOR_END}
	
re: fclean all

.PHONY: all clean fclean re

