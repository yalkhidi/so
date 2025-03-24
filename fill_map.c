/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:11 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/24 13:23:38 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void    load_imgs(t_game *game)
// {
//     game->bg = malloc(sizeof(t_img));
//     game->wall = malloc(sizeof(t_img));
//     game->space = malloc(sizeof(t_img));
//     game->col = malloc(sizeof(t_img));
//     game->player = malloc(sizeof(t_img));
//     game->exit = malloc(sizeof(t_img));
    
//     game->bg->img = mlx_xpm_file_to_image(game->mlx, "tiles/bg.xpm", &game->bg->width, &game->bg->height);
// }

void    free_game(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if(game->img)
    {
        mlx_destroy_image(game->mlx, game->img->img);
        free(game->img);
    }
    if (game->mlx)
        free(game->mlx);
    if(game->area)
    {
        free_split(game->area->map);
        free(game->area);
    }
    free(game);
}

void    fill_bg(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->area->height)
    {
        j = 0;
        while (j < game->area->width)
        {
            game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/bg.xpm", &game->img->width, &game->img->height);
            mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
            j++;
        }
        i++;
    }
}

void    fill_map(t_game *game)
{
    int i;
    int j;

    fill_bg(game);
    i = 0;
    while (i < game->area->height)
    {
        j = 0;
        while (j < game->area->width)
        {
            if (game->area->map[i][j] == '1')
                fill_wall(game, i, j);
            else if (game->area->map[i][j] == '0')
                fill_space(game, i, j);
            else if (game->area->map[i][j] == 'C')
                fill_col(game, i, j);
            else if (game->area->map[i][j] == 'P')
                fill_player(game, i, j);
            else if (game->area->map[i][j] == 'E')
                fill_exit(game, i, j);
            j++;
        }
        i++;
    }
}
