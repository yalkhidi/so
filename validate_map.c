/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:23 by codespace         #+#    #+#             */
/*   Updated: 2025/03/24 14:07:35 by yalkhidi         ###   ########.fr       */
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

t_area	*check_map(char *filename)
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
	if (is_valid_map(area))
		return (area);
	print_message("Error\nNovalid path in the map.\n");
	return (NULL);
}
