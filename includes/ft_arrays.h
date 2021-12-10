/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrays.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:55:22 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 13:53:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAYS_H
# define FT_ARRAYS_H

typedef struct s_int_array
{
	int	*array;
	int	width;
	int	height;
}	t_int_array;

t_int_array	get_array(int width, int height);
int			*get_elem(int *array, int x, int y);

#endif
