/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:36:59 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/24 14:21:03 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
//     char *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int	main(int ac, char **av)
{
    t_game  game;
    // t_area  *area;
    if(ac == 2)
    {
        // game = malloc(sizeof(t_game));
        game.area = check_map(av[1]);
        printf("map check done.%d\n", game.area->collect_count);
        game.mlx = mlx_init();
        game.win = mlx_new_window(game.mlx, game.area->width * 100,  game.area->height * 100, "SO_LONG");
        game.img = malloc(sizeof(t_img));
        fill_map(&game);
        mlx_loop(game.mlx);
        free_game(&game);
    }
    
}

// int	main(void)
// {
// 	char	*filename;
//     t_area  *area;

// 	filename = "map.ber";
// 	area = check_map(filename);
// 	printf("map parsing is complete, %d\n", area->collect_count);
//     free_split(area->map);
//     free(area);
// }

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
        
        // img.img = mlx_xpm_file_to_image(mlx, "tiles/bg.xpm", &img.width, &img.height);
        // if(!img.img)
        //     print_message("failed to image\n");
        // printf("Image width: %d, Image height: %d\n", img.width, img.height);
       
        // mlx_win = mlx_new_window(mlx,map->width *img.width , map->height * img.height, "Hello World!");
        // if(!mlx_win)
        //     print_message("failed to open window\n");
        
        // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// void    fill_map(char **map, )

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_img   img;
//     int     img_width;
//     int     img_height;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Image Example");

//     img.img =mlx_xpm_file_to_image(mlx, "tiles/floor.png", &img_width, &img_height);
//     if (!img.img)
//     {
//         printf("Error: Failed to load image.\n");
//         return (1);
//     }

//     printf("Image width: %d, Image height: %d\n", img_width, img_height);

//     mlx_put_image_to_window(mlx, mlx_win, img.img, 20, 20);
//     mlx_loop(mlx);

//     return (0);
// }
