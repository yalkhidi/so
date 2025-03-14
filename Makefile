CC:= cc
CCFLAGS:= -Wall -Werror -Wextra
MLX:= minilibx_opengl_20191021
MLX_FLAG:= -L$(MLX) -lmlx -framework OpenGL -framework AppKit
LIBFT:= libft/libft.a
GNL:= get_next_line/gnl.a
FILES:= parse.c
MAIN:= main.c
BONUS:= 

HEADER:= so_long.h
NAME:= solong.a

OFILES:= $(FILES:.c=.o)
OBONUS:= $(BONUS:.c=.o)

all: $(NAME) $(LIBFT) $(GNL) solong

%.o: %.c $(HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft
$(GNL):
	make -C get_next_line

$(NAME): $(OFILES)
	ar -crs $(NAME) $(OFILES) 

solong:
	$(CC) $(CCFLAGS) $(NAME) $(MAIN) $(LIBFT) $(GNL) -o so_long

bonus: $(OBONUS) 
	ar -crs $(NAME) $(OBONUS)

clean:
	make clean -C libft
	make clean -C get_next_line
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	make fclean -C libft
	make fclean -C get_next_line
	rm -f $(NAME) so_long

re: fclean all
.PHONY: all clean fclean re