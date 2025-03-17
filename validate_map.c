/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/17 17:38:11 by yalkhidi         ###   ########.fr       */
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

// bool	check_map(char *filename)
// {
// 	t_area	area;
// 	char	**map;
// 	t_area	*play_pos;
// 	bool	found;

// 	area.height = 0;
// 	area.width = 0;
// 	check_filename(filename);
// 	validate_map_walls(filename);
// 	validate_map_shape(filename, &area);
// 	validate_map_elements(filename);
// 	validate_map_elements2(filename);
// 	validate_invalid_elements(filename);
// 	validate_start_exit(filename);
// 	map = map_to_array(filename);
// 	play_pos = find_p(map);
// 	if (!play_pos)
// 		print_message("Error\n Play position not found.\n");
// 	found = valid_path(map, play_pos, area);
// 	if (!found)
// 		print_message("Error\n No valid path.\n");
// 	return (found);
// }

	// printf("Validated filename\n");
	// printf("Validated map walls\n");
	// printf("Validated map shape\n");
	// printf("Validated map elements\n");
	// printf("Validated map elements2\n");
	// printf("Validated map invalid elements\n");
	// printf("Validated start exit\n");
