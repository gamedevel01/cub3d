NAME		= cub3d

CC			= gcc

HEADER		= cub3d.h

PARSERDIR	= parser/

SRC			=	main.c error.c ft_cub3d_utils.c \
				$(PARSERDIR)parser_color.c $(PARSERDIR)parser_map.c \
				$(PARSERDIR)parser_resolution.c $(PARSERDIR)parser_texture.c \
				$(PARSERDIR)parser.c \
				

OBJS		= ${SRC:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= libmlx.dylib -framework OpenGL -framework AppKit

LIB			= libft.a

LIBFTDIR	= libft/

$(NAME): 
	make -C libft
	${CC} ${MLXFLAGS} ${SRC} libft.a

all: $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -rf $(NAME)
	
re: fclean all

.PHONY:clean fclean
