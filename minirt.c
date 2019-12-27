/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 16:21:19 by pde-bakk      #+#    #+#                 */
/*   Updated: 2019/12/27 16:42:21 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	put_pixel(t_data *my_mlx, int x, int y, int color)
{
	int pos;

	if (x >= 0 && x < 1280 && y >= 0 && y < 720)
	{
		pos = y * my_mlx->line_length + x * (my_mlx->bpp / 8);
		*(my_mlx->addr + pos + 0) = (char)((color & 0x00FFFFFF) >> 0);
		*(my_mlx->addr + pos + 1) = (char)((color & 0x0000FF00) >> 8);
		*(my_mlx->addr + pos + 2) = (char)((color & 0x00FF0000) >> 16);
	}
}

t_data	*init_my_mlx(int fd)
{
	t_data	*my_mlx;

	my_mlx = malloc(sizeof(t_data));
	if (my_mlx == NULL)
		return (NULL);
	my_mlx->mlx_ptr = mlx_init();
	ft_parser(my_mlx, fd);
	printf("bitch ass\n");
	my_mlx->mlx_img = mlx_new_image(my_mlx->mlx_ptr, 800, 600);
	my_mlx->addr = mlx_get_data_addr(my_mlx->mlx_img, &my_mlx->bpp, &my_mlx->line_length, &my_mlx->endian);
//	put_objects(my_mlx, fd);
	put_pixel(my_mlx, 10, 10, 255);
	put_square(my_mlx, 100, 50, 50, 255);
	put_square(my_mlx, 100, 100, 75, 255 * 255 * 255);
	put_square(my_mlx, 300, 250, 99, 255 * 255);
	put_square(my_mlx, 750, 550, 49, 255);
	my_mlx->win_ptr = mlx_new_window(my_mlx->mlx_ptr, 800, 600, "Printing vierkantjes like a motherfucking boss bitch");
	return (my_mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_data	*my_mlx;

	if (argc != 2)
	{
		write(2, "Error\nan explicit error message of your choice\n", 47);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	my_mlx = init_my_mlx(fd);
	mlx_put_image_to_window(my_mlx->mlx_ptr, my_mlx->win_ptr, my_mlx->mlx_img, 0, 0);
	mlx_loop(my_mlx->win_ptr);
}
