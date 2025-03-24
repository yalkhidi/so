# CC:= cc
# CCFLAGS:= -Wall -Wextra

# # MLXFLAG:= -Lmlx -lmlx -framework OpenGL -framework AppKit
# MLXFLAG:= -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# LIBFT:= libft/libft.a
# GNL:= get_next_line/gnl.a
# MLX:= mlx/libmlx.a

# FILES:= fill_map.c main.c print_messages.c struct_info.c validate_map.c validate_map_invalid_elements.c validate_map_walls.c fill_elements.c flood_fill.c validate_map_elements.c validate_map_shape.c
# BONUS:= 

# HEADER:= so_long.h
# NAME:= solong

# OFILES:= $(FILES:.c=.o)
# OBONUS:= $(BONUS:.c=.o)

# all:$(MLX) $(LIBFT) $(GNL)  $(NAME)

# %.o: %.c $(HEADER)
# 	$(CC) $(CCFLAGS) -Imlx -c $< -o $@

# $(LIBFT):
# 	make -C libft
# $(GNL):
# 	make -C get_next_line
# $(MLX):
# 	make -C mlx

# # $(NAME): $(OFILES)
# # $(CC) $(CCFLAGS) $(OFILES) $(LIBFT) $(GNL) $(MLX) $(MLXFLAG) -o $(NAME)
# $(NAME): $(OFILES) 
# 	$(CC) $(CCFLAGS) $(OFILES) $(LIBFT) $(GNL) -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd -o $(NAME)
# bonus: $(OBONUS) 
# 	ar -crs $(NAME) $(OBONUS)

# clean:
# 	make clean -C libft
# 	make clean -C get_next_line
# 	make clean -C mlx
# 	rm -f $(OFILES) $(OBONUS)

# fclean: clean
# 	make fclean -C libft
# 	make fclean -C get_next_line
# 	make clean -C mlx
# 	rm -f $(NAME)

# re: fclean all
# .PHONY: all clean fclean re


CC:= cc
CCFLAGS:= -Wall -Werror -Wextra

MLXFLAG:= -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

LIBFT:= libft/libft.a
GNL:= get_next_line/gnl.a
MLX:= mlx/libmlx.a

FILES:= fill_elements.c fill_map.c struct_info.c flood_fill.c main.c validate_map_elements.c validate_map_shape.c  print_messages.c validate_map.c  validate_map_invalid_elements.c  validate_map_walls.c
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





# CC:= cc
# CCFLAGS:= -Wall -Werror -Wextra

# LIBFT:= libft/libft.a
# GNL:= get_next_line/gnl.a


# FILES:= struct_info.c flood_fill.c main.c validate_map_elements.c validate_map_shape.c  print_messages.c validate_map.c  validate_map_invalid_elements.c  validate_map_walls.c
# BONUS:= 

# HEADER:= so_long.h
# NAME:= solong

# OFILES:= $(FILES:.c=.o)
# OBONUS:= $(BONUS:.c=.o)

# all: $(LIBFT) $(GNL) $(NAME)

# %.o: %.c $(HEADER)
# 	$(CC) $(CCFLAGS)  -c $< -o $@

# $(LIBFT):
# 	make -C libft
# $(GNL):
# 	make -C get_next_line


# $(NAME): $(OFILES)
# 	$(CC) $(CCFLAGS) $(OFILES) $(LIBFT) $(GNL)  -o $(NAME)

# bonus: $(OBONUS) 
# 	ar -crs $(NAME) $(OBONUS)

# clean:
# 	make clean -C libft
# 	make clean -C get_next_line
# 	rm -f $(OFILES) $(OBONUS)

# fclean: clean
# 	make fclean -C libft
# 	make fclean -C get_next_line
# 	rm -f $(NAME)

# re: fclean all
# .PHONY: all clean fclean re