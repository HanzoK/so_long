/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:20:27 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/25 13:15:22 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

// Splits the file content into the map_grid and handles memory issues
int	split_content_to_map_grid(char *txt, t_game_data *game)
{
	int	y;

	y = 0;
	ft_putstr_fd("Before split\n", 2);
	game->map_grid = ft_split(txt, '\n');
	ft_putstr_fd("After split\n", 2);
	free(txt);
	ft_putstr_fd("Before free txt\n", 2);
	if (!game->map_grid || !game->map_grid[0])
	{
		ft_putstr_fd("Here\n", 2);
		if (game->map_grid)
			ft_free(game->map_grid);
		return (FAIL);
	}
	ft_putstr_fd("Before returning\n", 2);
	return (SUCCESS);
}

// Main function that coordinates reading and processing the file
int	open_ber_file(char *str, t_game_data *game)
{
	char	*file_content;

	file_content = read_file_content(str);
	if (!file_content)
		return (FAIL);
	ft_putstr_fd("Before split\n", 2);
	if (!split_content_to_map_grid(file_content, game))
		return (ft_putstr_fd("Before\n", 2), free(game), ft_putstr_fd("After\n", 2), FAIL);
	ft_putstr_fd("Before returning 2\n", 2);
	return (SUCCESS);
}

void	ber_file(char *str)
{
	char	*dot_position;

	dot_position = ft_strrchr(str, '.');
	if (!dot_position || ft_strcmp(dot_position, ".ber") != 0)
	{
		ft_putstr_fd("Error\nDo you not know .ber files?\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	set_mlx_hook(t_game_data *game)
{
	ft_printf("Move: 0\n");
	mlx_hook(game->window_ptr, 2, 1L, key_press_handler, game);
	mlx_hook(game->window_ptr, 17, 1L, thanos_snap, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_putstr_fd("Error\nMust use a .ber file as argument. Duh.\n", 2);
		else
			ft_putstr_fd("Error\nOnly 1 map allowed, dude. Really?\n", 2);
		exit(EXIT_FAILURE);
	}
	ber_file(argv[1]);
	if (!(open_ber_file(argv[1], &game)))
		exit(EXIT_FAILURE);
	ft_putstr_fd("0\n", 2);
	map_grid_checker(&game);
	ft_putstr_fd("1\n", 2);
	window_init(&game);
	ft_putstr_fd("2\n", 2);
	image_init(&game);
	ft_putstr_fd("3\n", 2);
	set_mlx_hook(&game);
	return (0);
}
