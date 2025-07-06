/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:20:45 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/25 13:30:53 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

void	move_player(t_game_data *game, int new_y, int new_x)
{
	if (game->map_grid[new_y][new_x] == '1' ||
		(game->map_grid[new_y][new_x] == 'E' && game->collectible_count))
		return ;
	if (game->map_grid[new_y][new_x] == 'C')
		game->collectible_count--;
	else if (game->map_grid[new_y][new_x] == 'E' && !game->collectible_count)
		thanos_snap(game, 1);
	game->map_grid[game->player_pos_y][game->player_pos_x] = '0';
	game->map_grid[new_y][new_x] = 'P';
	texture_load(&game->floor_image, game, game->player_pos_x,
		game->player_pos_y);
	texture_load(&game->player_image, game, new_x, new_y);
	game->player_pos_y = new_y;
	game->player_pos_x = new_x;
	game->movement_count++;
	ft_printf("Move: %d\n", game->movement_count);
}

void	ft_free(char **array)
{
	int	y;

	y = 0;
	if (!array)
		return ;
	while (array[y])
	{
		free(array[y]);
		y++;
	}
	free(array);
}

void	free_map_on_error(t_game_data *game)
{
	int	y_index;

	if (game->map_grid)
	{
		y_index = 0;
		while (game->map_grid[y_index])
		{
			free(game->map_grid[y_index]);
			y_index++;
		}
		free(game->map_grid);
		game->map_grid = NULL;
	}
	ft_putstr_fd("Error\nInvalid map type, FOOL.\n", 2);
	exit (EXIT_FAILURE);
}
