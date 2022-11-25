/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:48:39 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/24 13:43:55 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_pars
{
	size_t	count;
	size_t	len;
	int		args;
	char	*map_path;
	char	**lines;
	int		coins;
	int		exits;
	int		player;
}	t_pars;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**lines;
	void	*wall;
	void	*door;
	void	*player;
	void	*coins;
	void	*ground;
	int		width;
	int		player_x;
	int		player_y;
	int		collect;
	int		moves;
}	t_data;

char	*get_next_line(int fd);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strstr(const char *str, const char *to_find);
void	ft_print_errors(int num);
void	ft_lines_count(t_pars *var);
void	ft_read_map(t_pars *var);
void	ft_check_walls(t_pars *var);
void	ft_check_coin_exit_player(t_pars *var);
void	ft_check_path_errors(t_pars *var);
void	ft_check_map_errors(t_pars *var);
void	ft_check_characters(char c, t_pars *var);
void	ft_mlx_put_image(t_data *data, int i, int j);
void	ft_mlx_put_image_plus(t_data *data, int i, int j);
void	ft_mlx_draw_image(t_data *data);
void	ft_key_plus(t_data *data, int x, int y);
void	ft_key(t_data *data, int x, int y);
int		ft_mlx_keys(int keycode, t_data *data);
int		ft_clear_window(t_data *data);
void	ft_mlx(t_pars *var, t_data *data);

#endif