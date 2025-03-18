#include "so_long.h"

char	**duplicat_map(char **map, int height)
{
	char	**cpy_map;
	int i;

	i = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (height + 1));
	if(!cpy_map)
	{
		return (NULL);
	}
	while(map[i])
	{
		cpy_map[i] = ft_strdup(map[i]);
		if(!cpy_map[i])
		{
			while(i--)
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
	// printf("FLOOD FILL\n");
	if (x < 0 || x >= area->height || y < 0 || y >= area->width)
		return; 
	if (area->map[x][y] == '1' || area->map[x][y] == 'F')
		return;  

	area->map[x][y] = 'F';
	flood_fill(area, map, x + 1, y);
	flood_fill(area, map, x - 1, y);
	flood_fill(area, map, x, y + 1);
	flood_fill(area, map, x, y - 1);
}

int	check_valid_c_e(char c, char f, char **map)
{
	if(c == 'C' && f != 'F')
	{
		free(map);
		print_message("Error\nCollectible not reached\n.");
	}
	if(c == 'E' && f != 'e')
	{
		free(map);
		print_message("Error\nExit not reached\n.");
	}
	return (1);
}

int	is_valid_map(t_area *area)
{
	char **map_copy;
	int	x;
	int	y;

	map_copy = duplicat_map(area->map, area->height);
	if(!map_copy)
		printf("Error\nMemory aLLOCATION FAILED.\n");
	printf("map copy allocation success\n");
	flood_fill(area, map_copy, area->player_x, area->player_y);
	printf("flood fill success\n");
	x = 0;
	int i = 0;
	int j = 0;
	printf("copymap f\n");
	while(area->map[i])
	{
		j = 0;
		while(area->map[i][j])
		{
			printf("%c", area->map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
	while(map_copy[x])
	{
		y = 0;
		while(map_copy[x][y])
		{
			check_valid_c_e(area->map[x][y], map_copy[x][y], map_copy);
			y++;
		}
		x++;
	}
	free(map_copy);
	printf("map has a valid path\n");
	return (1);
}
