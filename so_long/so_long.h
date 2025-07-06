/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjkim <hanjkim@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:21:45 by hanjkim           #+#    #+#             */
/*   Updated: 2024/09/25 13:28:42 by hanjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define PIXEL 50
# define MAX_INT 2147483648
# define FAIL 0
# define SUCCESS 1

typedef struct s_image
{
	void	*mlx_img_ptr;
	int		width;
	int		height;
}	t_image;

typedef struct s_game_data
{
	char			**map_grid;
	int				map_height;
	int				map_width;
	int				player_pos_x;
	int				player_pos_y;
	int				player_count;
	int				exit_count;
	int				collectible_count;
	int				movement_count;
	void			*mlx_ptr;
	void			*window_ptr;
	void			*frame_image_ptr;
	int				exit_found;
	t_image			player_image;
	t_image			wall_image;
	t_image			floor_image;
	t_image			collectible_image;
	t_image			exit_image;
}	t_game_data;

//Check ber file
void	ber_file(char *str);
int		open_ber_file(char *str, t_game_data *game);
int		open_file_for_reading(char *str);
char	*read_from_file(int fd);
char	*read_file_content(char *str);
int		read_and_append(int fd, char **txt);
int		close_file(int fd, char *txt);

//Map validation
char	**validate_map_grid_allocation(t_game_data *game);
void	map_grid_checker(t_game_data *game);
void	flood_fill(t_game_data *game, int y, int x, char **dupe_map);
void	check_positions(t_game_data *game);
int		is_map_rectangular(t_game_data *game);
int		is_map_valid(t_game_data *game, int y, int x);
int		valid_path_checker(t_game_data *game);
int		check_valid_path(t_game_data *game, char **temp_map);
int		check_valid_walls(t_game_data *game);
int		check_all_collectible(char **temp);

//Window and image generation
void	window_init(t_game_data *game);
void	texture_load(t_image *image, t_game_data *game, int x_pos, int y_pos);
void	image_to_window(t_game_data *game);
void	image_init(t_game_data *game);

//Setting movement
void	set_hook(t_game_data *game);
void	move_player(t_game_data *game, int new_y, int new_x);
void	up(t_game_data *game);
void	down(t_game_data *game);
void	left(t_game_data *game);
void	right(t_game_data *game);
int		key_press_handler(int key, t_game_data *game);

//Utilities
char	*ft_strjoin_so_long(char *s1, char *s2);
void	ft_free(char **temp);
void	free_map_on_error(t_game_data *game);
void	free_images_on_error(t_game_data *game);

//Avengers
int		thanos_snap(t_game_data *game, int success);

#endif
