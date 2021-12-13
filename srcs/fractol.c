/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:09:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 11:18:48 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	start_fractol(int ac, char **av)
{
	void	*mlx_ptr;
	void	*window_ptr;

	(void) ac;
	(void) av;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	window_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!window_ptr)
	{
		destroy_everything(&mlx_ptr, &window_ptr);
		return (2);
	}
	mlx_loop(mlx_ptr);
	destroy_everything(&mlx_ptr, &window_ptr);
	return (0);
}
