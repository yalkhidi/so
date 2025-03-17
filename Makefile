CC:= cc
CCFLAGS:= -Wall -Werror -Wextra

MLXFLAG:= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT:= libft/libft.a
GNL:= get_next_line/gnl.a
MLX:= mlx/libmlx.a

FILES:= mlx.c main.c validate_map_elements.c validate_map_shape.c  print_messages.c validate_map.c  validate_map_invalid_elements.c  validate_map_walls.c
BONUS:= 

HEADER:= so_long.h
NAME:= solong

OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(LIBFT) $(GNL) $(MLX) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -I$(MLX) -c $< -o $@

$(LIBFT):
	make -C libft
$(GNL):
	make -C get_next_line
$(MLX):
	make -C mlx

$(NAME): $(OFILES)
	$(CC) $(CCFLAGS) $(MLXFLAG) $(OFILES) $(LIBFT) $(GNL) $(MLX) -o $(NAME)

bonus: $(OBONUS) 
	ar -crs $(NAME) $(OBONUS)

clean:
	make clean -C libft
	make clean -C get_next_line
	make clean -C mlx
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	make clean -C mlx
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re