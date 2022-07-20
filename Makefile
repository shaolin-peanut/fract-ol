#Compilation setting

NAME=fract-ol
CC=gcc
CFLAGS=-Wall -Wextra -Werror 
##-fsanitize=address

#Sources
DIR_SRC=./sources
SRCS=	${DIR_SRC}/main.c\
		${DIR_SRC}/fractals.c\
		${DIR_SRC}/utils.c\
		${DIR_SRC}/hook_utils.c\
		${DIR_SRC}/zoom.c\

DIR_OBJ=./objs
OBJS=${addprefix ${DIR_OBJ}/, ${notdir ${SRCS:.c=.o}}}

#Find the os
UNAME_S := $(shell uname -s)

#Linux
#$(CC)
#$(OBJS) -L${DIR_LIB_MLX}/ -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
ifeq ($(UNAME_S),Linux)
		DIR_LIB_MLX= ./mlx-linux
		DIR_LIB_SYS= ./usr/lib
		OFLAGS=-L${DIR_LIB_MLX} -lmlx  -I${DIR_LIB_MLX} -lXext -lX11 -lm -lz
endif
#L/usr/lib

#Apple
#$(CC) $(OBJS)		 -L${DIR_LIB_MLX}/ -Imlx -lmlx -o $(NAME)
#$(CC) $(OBJS) -L${DIR_LIB_M	LX}/ -Imlx-apple -lmlx -o $(NAME)

ifeq ($(UNAME_S),Darwin)
		DIR_LIB_MLX=libs/mlx-apple
		OFLAGS=-L${DIR_LIB_MLX} -lmlx -framework OpenGL -framework AppKit
endif

vpath %.c ${DIR_SRC}
RM=rm -f

all : ${NAME}

$(NAME):			 $(OBJS)
		#make -C ${DIR_LIB_MLX}
		$(CC) $(OBJS) -L${DIR_LIB_MLX} ${OFLAGS} -o $(NAME)

${DIR_OBJ}/%.o : %.c | ${DIR_OBJ}
		$(CC) ${CFLAGS} -I${DIR_LIB_MLX} -O3 -c $< -o $@

${DIR_OBJ} :
		@mkdir -p ${DIR_OBJ}

clean:
		#make clean -C ${DIR_LIB_MLX}
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
		#make re -C ${DIR_LIB_MLX}

norm:
		norminette ${SRCS} 
