/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:20:58 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/25 16:16:36 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	texture_load(t_image *image, t_game_data *game, int x_pos, int y_pos)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		image->mlx_img_ptr, PIXEL * x_pos, PIXEL * y_pos);
}

void	window_init(t_game_data *game)
{
	int	x_size;
	int	y_size;

	game->mlx_ptr = NULL;
	if (!game->mlx_ptr)
	{
		(ft_putstr_fd("Error\nFail init MLX\n", 2), ft_free(game->map_grid));
		exit(EXIT_FAILURE);
	}
	mlx_get_screen_size(game->mlx_ptr, &x_size, &y_size);
	if (game->map_height * PIXEL > y_size || game->map_width * PIXEL > x_size)
	{
		(ft_putstr_fd("Error\nMap too big.\n", 2), ft_free(game->map_grid));
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	game->window_ptr = mlx_new_window(game->mlx_ptr,
			game->map_width * PIXEL, game->map_height * PIXEL, "so_long");
	if (!game->window_ptr)
	{
		ft_putstr_fd("Error\nFailed to create window. Tsk Tsk.\n", 2);
		(mlx_destroy_display(game->mlx_ptr), free(game->mlx_ptr));
		exit(EXIT_FAILURE);
	}
}
