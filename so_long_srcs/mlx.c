/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:58:06 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/24 07:38:55 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx(t_pars *var, t_data *data)
{
	int		x;

	x = data->width;
	data->lines = var->lines;
	data->mlx = mlx_init();
	if (!(data->mlx))
		ft_print_errors(10);
	data->window = mlx_new_window(data->mlx, var->len * 64, \
			var->count * 64, "so_long");
	if (!(data->window))
		ft_print_errors(10);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./xpm/wall.xpm", &x, &x);
	data->door = mlx_xpm_file_to_image(data->mlx, "./xpm/door.xpm", &x, &x);
	data->player = mlx_xpm_file_to_image(data->mlx, "./xpm/player.xpm", &x, &x);
	data->ground = mlx_xpm_file_to_image(data->mlx, "./xpm/ground.xpm", &x, &x);
	data->coins = mlx_xpm_file_to_image(data->mlx, "./xpm/coin.xpm", &x, &x);
	if (!(data->wall) || !(data->door) || !(data->player) \
		|| !(data->ground) || !(data->coins))
		ft_print_errors(11);
	data->collect = 0;
	data->moves = 0;
	ft_mlx_draw_image(data);
	mlx_key_hook(data->window, ft_mlx_keys, data);
	mlx_hook(data->window, 17, 0, ft_clear_window, data);
	mlx_loop(data->mlx);
}
