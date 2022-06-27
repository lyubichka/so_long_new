NAME = so_long
# CFLAGS = -Wall -Werror -Wextra
FLAGS = -crs
mlx = ./mlx/libmlx.a
FILES = so_long.c init_map.c check_format.c check_map.c utils.c game_hook.c
OBJECTS = $(FILES:.c=.o)
LIBFT = cd libft && make
LIB = libft/libft.a
OS	= $(shell uname)

ifeq ($(OS), Linux)
	MLX_FLAGS = ./mlx/libmlx.a -Lmlx_linux -Imlx_linux -lXext -lX11 -lm -lz
	MLX_PATH = mlx
else
	MLX_FLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
	MLX_PATH = mlx
endif


$(NAME)	:
		$(LIBFT)
		make -C ./libft
		make -C ./mlx
		gcc $(CFLAGS) $(FILES) $(LIB) $(MLX_FLAGS) -o so_long 
all : $(NAME)
clean :
		rm -f $(OBJS)
		make clean -C mlx
	
fclean : clean
		rm -f $(NAME)
		make clean -C mlx
re : fclean all