/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:21:02 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/24 19:33:12 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

int	thanos_snap(t_game_data *game, int success)
{
	if (game->map_grid)
		ft_free(game->map_grid);
	if (game->frame_image_ptr)
		mlx_destroy_image(game->mlx_ptr, game->frame_image_ptr);
	if (game->player_image.mlx_img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_image.mlx_img_ptr);
	if (game->wall_image.mlx_img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall_image.mlx_img_ptr);
	if (game->exit_image.mlx_img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit_image.mlx_img_ptr);
	if (game->collectible_image.mlx_img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible_image.mlx_img_ptr);
	if (game->floor_image.mlx_img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor_image.mlx_img_ptr);
	if (game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->mlx_ptr)
		(mlx_destroy_display(game->mlx_ptr), free(game->mlx_ptr));
	if (success)
	{
		ft_putstr_fd("Game Clear! Well done!\n", 1);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
	return (SUCCESS);
}
