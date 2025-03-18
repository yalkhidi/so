/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:28:29 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/18 13:00:01 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
    char    *filename;

    filename = "map.ber";
    check_map(filename);
    printf("map parsing is complete");
}


// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     void    *img;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "First Window");
//     mlx_loop(mlx);
//     img = mlx_new_image(mlx, 1920, 1080);
//     mlx_put_image_to_window(mlx, mlx_win, img, 0,0);
// }