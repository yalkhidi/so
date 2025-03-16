/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:28:29 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/16 11:10:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	*filename;

	filename = "map.ber";
	validate_map_shape(filename);
	check_map(filename);
}

/*
11111\n\0
*/