CC:= cc
CCFLAGS:= -Wall -Werror -Wextra


LIBFT:= libft/libft.a
GNL:= get_next_line/gnl.a


FILES:= struct_info.c flood_fill.c mlx.c main.c validate_map_elements.c validate_map_shape.c  print_messages.c validate_map.c  validate_map_invalid_elements.c  validate_map_walls.c
BONUS:= 

HEADER:= so_long.h
NAME:= solong

OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(LIBFT) $(GNL) $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CCFLAGS)  -c $< -o $@

$(LIBFT):
	make -C libft
$(GNL):
	make -C get_next_line


$(NAME): $(OFILES) 
	$(CC) $(CCFLAGS)  $(OFILES) $(LIBFT) $(GNL) -o $(NAME)

bonus: $(OBONUS) 
	ar -crs $(NAME) $(OBONUS)

clean:
	make clean -C libft
	make clean -C get_next_line
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re