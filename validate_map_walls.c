/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:43 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/16 11:41:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_outer_wall(char *previous, int fd)
{
	int	i;

	if (!previous)
	{
		free(previous);
		close(fd);
		print_message("Error\nMap file is Empty.\n");
	}
	i = 0;
	while (previous[i] && previous[i] != '\n')
	{
		if (previous[i] != '1')
		{
			free(previous);
			while (previous)
			{
				free(previous);
				previous = get_next_line(fd);
			}
			close(fd);
			print_message("Error\nMap is not surrounded by walls.\n");
		}
		i++;
	}
}

void	check_side_walls(char *line, char *previous, int fd)
{
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
	{
		free(line);
		free(previous);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		print_message("Error\nMap is not surrounded by walls.\n");
	}
}

void	validate_map_walls(char *filename)
{
	char	*line;
	char	*prev_line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	prev_line = get_next_line(fd);
	if (!prev_line)
		check_outer_wall(prev_line, fd);
	check_outer_wall(prev_line, fd);
	line = get_next_line(fd);
	while (line)
	{
		check_side_walls(line, prev_line, fd);
		free(prev_line);
		prev_line = line;
		line = get_next_line(fd);
	}
	check_outer_wall(prev_line, fd);
	free(prev_line);
	close(fd);
}
