/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:50:38 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/03/24 14:18:05 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    fill_wall(t_game *game, int i, int j)
{
    game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/wall.xpm", &game->img->width, &game->img->height);
    if(!game->img->img)
    {
        mlx_destroy_window(game->mlx, game->win);
        print_message("Error\nFailed to load a wall.\n");
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
    mlx_destroy_image(game->mlx, game->img->img);
    printf("done filling walls.\n");
}

void    fill_space(t_game *game, int i, int j)
{
    game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/free_space.xpm", &game->img->width, &game->img->height);
    if(!game->img->img)
    {
        mlx_destroy_window(game->mlx, game->win);
        print_message("Error\nFailed to load free space.\n");
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
    mlx_destroy_image(game->mlx, game->img->img);
}

void    fill_col(t_game *game, int i, int j)
{
    fill_space(game, i, j);
    game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/cherry.xpm", &game->img->width, &game->img->height);
    if(!game->img->img)
    {
        mlx_destroy_window(game->mlx, game->win);
        print_message("Error\nFailed to load a collectible.\n");
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
    mlx_destroy_image(game->mlx, game->img->img);
}

void    fill_player(t_game *game, int i, int j)
{
    fill_space(game, i, j);
    game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/Player.xpm", &game->img->width, &game->img->height);
    if(!game->img->img)
    {
        mlx_destroy_window(game->mlx, game->win);
        print_message("Error\nFailed to load player.\n");
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
    mlx_destroy_image(game->mlx, game->img->img);
}

void    fill_exit(t_game *game, int i, int j)
{
    game->img->img = mlx_xpm_file_to_image(game->mlx, "tiles/exit.xpm", &game->img->width, &game->img->height);
    if(!game->img->img)
    {
        mlx_destroy_window(game->mlx, game->win);
        print_message("Error\nFailed to load exit.\n");
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, j * 100, i * 100);
    mlx_destroy_image(game->mlx, game->img->img);
}