/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:48:34 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/22 03:34:00 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_plus(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->ground,
		(data->player_x + x) * 64, (data ->player_y + y) * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->player,
		(data->player_x + x) * 64, (data ->player_y + y) * 64);
	mlx_put_image_to_window(data->mlx, data->window, data->ground,
		(data->player_x) * 64, (data ->player_y) * 64);
	data->lines[data->player_y][data->player_x] = '0';
	data->player_y += y;
	data->player_x += x;
	if (data->lines[data->player_y][data->player_x] == 'C')
		data->collect--;
	data->lines[data->player_y][data->player_x] = 'P';
	data->moves++;
	ft_putnbr(data->moves);
	ft_putchar('\n');
}

void	ft_key(t_data *data, int x, int y)
{
	if (data->lines[data->player_y + y][data->player_x + x] == 'E' &&
		data->collect == 0)
	{
		data->moves++;
		mlx_clear_window(data->mlx, data->window);
		ft_putnbr(data->moves);
		ft_putchar('\n');
		exit (EXIT_SUCCESS);
	}
	if (data->lines[data->player_y + y][data->player_x + x] != 'E')
		ft_key_plus(data, x, y);
}

int	ft_mlx_keys(int keycode, t_data *data)
{
	if ((keycode == 13 || keycode == 126)
		&& data->lines[data->player_y - 1][data->player_x] != '1')
		ft_key(data, 0, -1);
	else if ((keycode == 0 || keycode == 123)
		&& data->lines[data->player_y][data->player_x - 1] != '1')
		ft_key(data, -1, 0);
	else if ((keycode == 1 || keycode == 125)
		&& data->lines[data->player_y + 1][data->player_x] != '1')
		ft_key(data, 0, 1);
	else if ((keycode == 2 || keycode == 124)
		&& data->lines[data->player_y][data->player_x + 1] != '1')
		ft_key(data, 1, 0);
	else if (keycode == 53)
	{
		mlx_clear_window(data->mlx, data->window);
		exit(EXIT_FAILURE);
	}
	return (0);
}
