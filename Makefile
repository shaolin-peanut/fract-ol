## SRCS	= 	${addprefix sources/, so_long.c map_checks.c map_generator.c player_movements.c player_animations.c enemy_movement.c}	\
			${addprefix get_next_line/, get_next_line.c	get_next_line_utils.c}
NAME = fractol
SRC = ${addprefix sources/, main.c algorithm.c utils.c}

FLGS = -Wall -Werror -Wextra -fsanitize=address -g3
OBJ = $(SRC:.c=.o)
HEAD = sources/fractol.h
CC = gcc
MLX_PATH	= 	./libraries/mlx/
LBFT_PATH	= 	./libraries/libft/
FRAMLIBS	= 	-L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:		libft mlx ${NAME}

.c.o:		
			${CC} ${FLGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME):	${OBJ} ${HEAD}
			${CC} ${FLGS} -I ${MLX_PATH} -I ${LBFT_PATH} ${OBJ} ${FRAMLIBS} -o ${NAME}

libft:
			@make -C ${LBFT_PATH}

mlx:
			@make -C ${MLX_PATH}

fclean:	clean
	rm -f $(NAME)
##	@make -C $(LBFT_PATH) clean
##	@make -C $(MLX_PATH) fclean

clean:
	rm -f $(OBJ)
	@make -C $(LBFT_PATH) clean
	@make -C $(MLX_PATH) clean

re:	fclean all

.PHONY:	all fclean clean re
