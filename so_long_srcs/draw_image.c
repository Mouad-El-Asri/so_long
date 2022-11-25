/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:56:34 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/24 07:38:31 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_put_image(t_data *data, int i, int j)
{
	if (data->lines[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->wall, j * 64, i * 64);
	else if (data->lines[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, \
			data->ground, j * 64, i * 64);
		mlx_put_image_to_window(data->mlx, data->window, \
			data->player, j * 64, i * 64);
		data->player_x = j;
		data->player_y = i;
	}
	else if (data->lines[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, \
			data->ground, j * 64, i * 64);
		mlx_put_image_to_window(data->mlx, data->window, \
			data->door, j * 64, i * 64);
	}
}

void	ft_mlx_put_image_plus(t_data *data, int i, int j)
{
	if (data->lines[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, \
			data->ground, j * 64, i * 64);
		mlx_put_image_to_window(data->mlx, data->window, \
			data->coins, j * 64, i * 64);
		data->collect++;
	}
	else if (data->lines[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->ground, j * 64, i * 64);
}

void	ft_mlx_draw_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			ft_mlx_put_image(data, i, j);
			ft_mlx_put_image_plus(data, i, j);
			j++;
		}
		i++;
	}
}
