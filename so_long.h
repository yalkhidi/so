/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:50:05 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/16 11:43:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

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
//          Map invalid
void	invalid_elements(char *line, int fd);
void	validate_invalid_elements(char *filename);

void	check_map(char *filename);
#endif