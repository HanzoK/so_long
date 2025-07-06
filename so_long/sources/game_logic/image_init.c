/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:48:37 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/24 19:38:24 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	init_image_pointers(t_game_data *game)
{
	game->frame_image_ptr = NULL;
	game->player_image.mlx_img_ptr = NULL;
	game->wall_image.mlx_img_ptr = NULL;
	game->collectible_image.mlx_img_ptr = NULL;
	game->floor_image.mlx_img_ptr = NULL;
	game->exit_image.mlx_img_ptr = NULL;
}

void	image_to_window(t_game_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_grid[y])
	{
		x = 0;
		while (game->map_grid[y][x])
		{
			texture_load(&game->floor_image, game, x, y);
			if (game->map_grid[y][x] == 'P')
				texture_load(&game->player_image, game, x, y);
			else if (game->map_grid[y][x] == 'C')
				texture_load(&game->collectible_image, game, x, y);
			else if (game->map_grid[y][x] == '1')
				texture_load(&game->wall_image, game, x, y);
			else if (game->map_grid[y][x] == 'E')
				texture_load(&game->exit_image, game, x, y);
			x++;
		}
		y++;
	}
}

void	load_image(t_game_data *game, t_image *img, char *path)
{
	img->mlx_img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&img->width, &img->height);
	if (!img->mlx_img_ptr)
	{
		ft_putstr_fd("Error\n Failed to load 1 of the images. Doofus.\n", 2);
		thanos_snap(game, 0);
	}
}

void	image_init(t_game_data *game)
{
	init_image_pointers(game);
	load_image(game, &game->player_image, "./sources/images/PLAYER.xpm");
	load_image(game, &game->wall_image, "./sources/images/WALL.xpm");
	load_image(game, &game->collectible_image, "./sources/images/COIN.xpm");
	load_image(game, &game->floor_image, "./sources/images/FLOOR.xpm");
	load_image(game, &game->exit_image, "./sources/images/EXIT.xpm");
	image_to_window(game);
}
