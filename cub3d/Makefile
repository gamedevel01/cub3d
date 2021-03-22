NAME	= cub3d

CC		= gcc

HEADER	= cub3d.h

SRC		=	parser.c error.c \
			parser_resolution.c parser_texture.c parser_color.c parser_map.c \
			ft_cub3d_utils.c main.c \

OBJS	= ${SRC:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

MLXFLAGS = libmlx.dylib -framework OpenGL -framework AppKit

LIB		= libft.a

$(NAME): 
	make -C liba
	${CC} ${MLXFLAGS} ${SRC} libft.a

all: $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}
re: fclean all

.PHONY:clean fclean
