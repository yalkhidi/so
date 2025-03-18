/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 14:04:34 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 4) || ext[4] != '\0' || ext == filename)
		print_message("Error\nInvalid map filename.\n");
}

void	check_map(char *filename)
{
	t_area	*area;

	area = NULL;
	check_filename(filename);
	printf("Validated filename\n");
	
	validate_map_walls(filename);
	printf("Validated map walls\n");
	
	validate_map_shape(filename);
	printf("Validated map shape\n");
	
	validate_map_elements(filename);
	printf("Validated map elements\n");
	
	validate_map_elements2(filename);
	printf("Validated map elements2\n");
	
	validate_invalid_elements(filename);
	printf("Validated map invalid elements\n");
	
	validate_start_exit(filename);
	printf("Validated start exit\n");
	
	area = collect_info(filename);
	printf("incheckmap\n");
	printf("width: %d\nheight: %d\n", area->width, area->height);
	printf("px: %d\npy: %d\n", area->player_x, area->player_y);
	int i = 0;
	int j = 0;
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
	is_valid_map(area);
}

