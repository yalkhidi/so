/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:43 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/14 15:08:12 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	print_message(char *message)
{
	write(2, message, ft_strlen(message));
	exit(1);
}

void	check_filename(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) || ext[4] != '\0' || ext == filename)
		print_message("Error: Invalid map filename.\n");
}

void	check_map(char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	if (line)
	{
		while (line[i])
		{
			if (line[i] != '1')
			{
				write(2, "Error: Map isnt surrounded by walls.\n", 38);
				exit(1);
			}
			i++;
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			while (line[i])
			{
				if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
				{
					write(2, "Error: Map isnt surrounded by walls.\n", 38);
					exit(1);
				}
				i++;
			}
			line = get_next_line(fd);
		}
	}
	else
	{
		write(2, "Error: Map file is empty\n", 26);
		exit(1);
	}
	close(fd);
}

void	check_if_rectangular(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		height;
	int		prev_w;

	fd = open(filename, O_RDONLY);
	printf("file opened\n");
	width = 0;
	height = 0;
	prev_w = 0;
	line = get_next_line(fd);
	if (line)
	{
		printf("first line read\n");
		height++;
		if (line[ft_strlen(line)] == '\0')
		{
			printf("'%s'", line);
			width = ft_strlen(line) - 1;
		}
		else
			printf("'%s' char at strlen '%c'", line, line[ft_strlen(line)]);
		while ((line = get_next_line(fd)))
		{
			prev_w = width;
			if (ft_strlen(line) == '\n')
				width = ft_strlen(line) - 1;
			if (width != prev_w)
				print_message("Error: Inconsistent map border.\n");
			height++;
		}
		if (!line)
		{
			if (width == height)
				print_message("Error: Map is not a rectangular.\n");
		}
	}
	else
	{
		print_message("Error: Map file is empty.\n");
	}
}

// int main(void)
// {
// 	char *filename = "map.txt";

// 	check_if_rectangular(filename);
// }
