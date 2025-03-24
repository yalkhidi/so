/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:23:00 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/24 13:16:08 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicat_map(char **map, int height)
{
	char	**cpy_map;
	int		i;

	i = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!cpy_map)
	{
		return (NULL);
	}
	while (map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		if (!cpy_map[i])
		{
			while (i--)
				free(cpy_map[i]);
			free(cpy_map);
			return (NULL);
		}
		i++;
	}
	cpy_map[i] = NULL;
	return (cpy_map);
}

void	flood_fill(t_area *area, char **map, int x, int y)
{
	if (x < 0 || x >= area->width || y < 0 || y >= area->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(area, map, x + 1, y);
	flood_fill(area, map, x - 1, y);
	flood_fill(area, map, x, y + 1);
	flood_fill(area, map, x, y - 1);
}

int	check_valid_c_e(char c, char f, char **map, t_area *area)
{
	if (c == 'C' && f != 'F')
	{
		free_split(map);
		free_split(area->map);
		free(area);
		print_message("Error\nCollectible not reached\n.");
	}
	if (c == 'E' && f == 'E')
	{
		free_split(map);
		free_split(area->map);
		free(area);
		print_message("Error\nExit not reached\n.");
	}
	return (1);
}

int	is_valid_map(t_area *area)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicat_map(area->map, area->height);
	if (!map_copy)
		printf("Error\nMemory allocation failed.\n");
	flood_fill(area, map_copy, area->player_x, area->player_y);
	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			check_valid_c_e(area->map[y][x], map_copy[y][x], map_copy, area);
			x++;
		}
		y++;
	}
	free_split(map_copy);
	printf("map has a valid path\n");
	return (1);
}
