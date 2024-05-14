/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:53:11 by tanselmo          #+#    #+#             */
/*   Updated: 2024/05/09 19:00:21 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define PIXEL 64

typedef struct s_game
{
	int				width;
	int				height;
	int				collect;
	int				player;
	int				exit;
	int				count;
	int				moves;
	int				x;
	int				y;
	char			**map;
	char			**dup;
	mlx_t			*init;
	mlx_image_t		*img_c;
	mlx_image_t		*img_p;
	mlx_image_t		*img_e;
	mlx_image_t		*img_f;
	mlx_image_t		*img_w;
	mlx_texture_t	*texture;
}	t_game;

//--------------------FLOOD FILL---------------------//
void	flood_fill(t_game *game, int y, int x);
void	valid_map(char **map);
//---------------------CHECKER-----------------------//
int		check_file(char	*argv);
int		check_map_size(char *argv);
void	check_content(t_game *game);
int		check_item_pos(t_game *game, int y, int x);
int		check_borders(t_game *game, int y, int x);
//----------------------CLOSE------------------------//
void	close_window(t_game *game);
//-----------------------INIT------------------------//
void	init_struct(t_game *game);
//-----------------------MAPS------------------------//
void	create_game(char *argv);
void	get_map(t_game *game, int fd);
void	get_size(t_game *game, char *argv);
//----------------------UTILS------------------------//
void	print_error(char *message);
int		open_file(char *argv);
void	free_matrix(char **matrix);
//----------------------ITEMS------------------------//
void	quantity_item(t_game *game);
void	get_player_pos(t_game *game);
//--------------------TEXTURES-----------------------//
void	set_textures(t_game *game);
void	put_textures(t_game *game);
void	put_floor(t_game *game);
//--------------------INIT MLX-----------------------//
void	init_mlx_game(t_game *g);
//--------------------MOVEMENTS----------------------//
void	set_moves(mlx_key_data_t key, void *param);
int		do_moves(t_game *g, int move);
//----------------------MOVES------------------------//
void	mov_up(t_game *g);
void	mov_down(t_game *g);
void	mov_right(t_game *g);
void	mov_left(t_game *g);

#endif