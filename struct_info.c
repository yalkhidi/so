/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:53:26 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/18 14:00:39 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_array(char *filename, t_area *area)
{
	int		fd;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file");
	area->map = (char **)malloc((area->height + 1) * sizeof(char *));
	if (!area->map)
		print_message("Error\nAllocation Failed");
	y = 0;
	while (y < area->height)
	{
		area->map[y] = get_next_line(fd);
		y++;
	}
	area->map[y] = NULL;
	close(fd);
}

void	find_player(t_area *area)
{
	int		x;
	int		y;

	x = 0;
	while (area->map[x])
	{
		y = 0;
		while (area->map[x][y])
		{
			if (area->map[x][y] == 'P')
			{
				area->player_x = x;
				area->player_y = y;
			}
			y++;
		}
		x++;
	}
}
void	find_map_area(char *filename, t_area *area)
{
	char	*line;
	int		height;
	int		first_width;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file.\n");
	line = get_next_line(fd);
	first_width = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	height = 0;
	while (line)
	{
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	area->height = height;
	area->width = first_width;
}
t_area	*collect_info(char *filename)
{
	t_area	*area;

	area = (t_area *)malloc(sizeof(t_area));
	if(!area)
	{
		print_message("collect info\n Allocation failed\n");
	}
	find_map_area(filename, area);
	// printf("width: %d\nheight: %d\n", area->width, area->height);
	map_to_array(filename, area);
	// int i = 0;
	// int j = 0;
	// while(area->map[i])
	// {
	// 	j = 0;
	// 	while(area->map[i][j])
	// 	{
	// 		printf("%c", area->map[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// printf("\n");
	find_player(area);
	// printf("px: %d\npy: %d\n", area->player_x, area->player_y);
	return (area);
}

