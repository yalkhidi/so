/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:28:29 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:46 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	char	*filename;
// 	bool	yes_exit;

// 	filename = "map.ber";
// 	yes_exit = check_map(filename);
// 	if (yes_exit)
// 		printf("exit found\n");
// 	else
// 		printf("No path\n");
// }


int main(void)
{
    void    *mlx;
    void    *mlx_win;
    void    *img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "First Window");
    mlx_loop(mlx);
    img = mlx_new_image(mlx, 1920, 1080);
    mlx_put_image_to_window(mlx, mlx_win, img, 0,0);
}