/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:37 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/14 19:27:41 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

#include "shiny.h"
#include "julia_set.h"

static void	fill_pts(t_complex *pts, t_fract_data *data, int width, int height);
static int	get_color(int speed, int max_speed);

void	draw_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data)
{
	int			x;
	int			y;
	void		*image;
	int			*buffer;
	t_shiny		*set;
	t_complex	pts[SIZE * SIZE];

	fill_pts(pts, fract_data, SIZE, SIZE);
	set = get_julia_set(pts, SIZE * SIZE, fract_data->c);
	y = 0;
	image = mlx_new_image(mlx_bp->mlx_ptr, SIZE, SIZE);
	buffer = (int *) mlx_get_data_addr(image, &x, &x, &x);
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			buffer[y * SIZE + x] = get_color(set[y * SIZE + x].value,
					MAX_SPEED);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_bp->mlx_ptr, mlx_bp->window_ptr, image, 0, 0);
	(void) mlx_bp;
	(void) fract_data;
}

static void	fill_pts(t_complex *pts, t_fract_data *data, int width, int height)
{
	int			x;
	int			y;
	t_complex	point;

	y = 0;
	while (y < height)
	{
		x = 0;
		point.y = (1.0 * y / height * (data->max - data->min)) + data->min;
		while (x < width)
		{
			point.x = (1.0 * x / width * (data->max - data->min)) + data->min;
			pts[y * width + x] = point;
			x++;
		}
		y++;
	}
}

static int	get_color(int speed, int max_speed)
{
	int	color;
	int	base_color;

	(void) max_speed;
	if (speed == -1)
		return (0xFF000000);
	color = 0;
	base_color = 255 - 1.0 / speed * 255;
	if (speed % 60 < 20)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 24;
		color += (int)(speed % 60 / 20.0 * 255) << 16;
	}
	else if (speed % 60 < 40)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 16;
		color += (int)(speed % 60 / 20.0 * 255) << 8;
	}
	else
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 8;
		color += (int)(speed % 60 / 20.0 * 255);
	}
	return (color);
}
