/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:24:02 by moel-asr          #+#    #+#             */
/*   Updated: 2022/11/22 01:55:53 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_srcs/so_long.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		ft_putnbr(n);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar((n + 48));
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
