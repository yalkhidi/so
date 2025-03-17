/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:53:26 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/17 17:10:46 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_to_array(char *filename)
{
	int		fd;
	char	**map;
	t_area	area;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_message("Error\nFailed to open file");
	area.height = 1;
	area.width = 1;
	validate_map_shape(filename, &area);
	printf("width: %d\nheight: %d\n", area.width, area.height);
	map = (char **)malloc((area.height + 1) * sizeof(char *));
	if (!map)
		print_message("Error\nAllocation Failed");
	i = 0;
	while (i < area.height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

t_area	*find_p(char **map)
{
	int		i;
	int		j;
	t_area	*point_p;

	point_p = (t_area *)malloc(sizeof(t_area));
	if (!point_p)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				point_p->width = j;
				point_p->height = i;
				return (point_p);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	flood_fill(char **map, int x, int y, bool *exit)
{
	if (*exit)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V' || *exit == true)
		return ;
	if (map[x][y] == 'E')
	{
		*exit = true;
		return ;
	}
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, exit);
	flood_fill(map, x - 1, y, exit);
	flood_fill(map, x, y + 1, exit);
	flood_fill(map, x, y - 1, exit);
}

bool	valid_path(char **map, int x, int y)
{
	bool	exit_found;

	exit_found = false;
	flood_fill(map, x, y, &exit_found);
	return (exit_found);
}
