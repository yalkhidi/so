/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:50:05 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/18 14:24:48 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
// # include </Users/yalkhidi/Desktop/so_long/mlx/mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_area
{
	int		width; // x j
	int		height; // y i
	char	**map;
	int		player_x;
	int		player_y;
}	t_area;

void	print_message(char *message);
//              MAP             //

//          Map file extention //
void	check_filename(char *filename);
//          Map shape
void	check_rectangular(int width, int height, int fd);
void	check_consistent(int width, int first_width, int fd, char *line);
void	validate_map_shape(char *filename);
//          Map walls
void	check_outer_wall(char *previous, int fd);
void	check_side_walls(char *line, char *previous, int fd);
void	validate_map_walls(char *filename);
//          Map elements
void	check_elements(char *line, int *e, int *c, int *s);
void	validate_map_elements(char *filename);
void	check_elements2(char *line, int *wall, int *space);
void	validate_map_elements2(char	*filename);
void	validate_start_exit(char *filename);
//          Map invalid elements
void	invalid_elements(char *line, int fd);
void	validate_invalid_elements(char *filename);

void	check_map(char *filename);
void	map_to_array(char *filename, t_area *area);
void	find_player(t_area *area);
void	count_collectibles(t_area *area);
t_area	*collect_info(char *filename);

char	**duplicat_map(char **map, int height);
void	flood_fill(t_area *area, char **map, int x, int y);
int	check_valid_c_e(char c, char f, char **map);
int	is_valid_map(t_area *area);
void	find_map_area(char *filename, t_area *area);


#endif