/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_plane.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Peer de Bakker <pde-bakk@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 18:06:05 by pde-bakk       #+#    #+#                */
/*   Updated: 2020/03/18 14:58:49 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			find_plane(t_plane *pl, t_data *my_mlx, int threadnr)
{
	t_vec3	sub;
	double	a;
	double	denom;
	double	t;

	sub = vec3_sub(pl->s, my_mlx->cam->s);
	denom = dotproduct(pl->normal, my_mlx->ray[threadnr]->v);
	if (denom > EPSILON)
	{
		a = dotproduct(sub, pl->normal);
		t = a / denom;
		if (t > 0)
			if (t < my_mlx->ray[threadnr]->length)
			{
				my_mlx->ray[threadnr]->length = t;
				my_mlx->ray[threadnr]->colour = pl->colour;
				my_mlx->ray[threadnr]->hitnormal = vec3_mult(pl->normal, -1);
				return (1);
			}
	}
	return (0);
}
