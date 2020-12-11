/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 07:15:58 by adelille          #+#    #+#             */
/*   Updated: 2020/12/11 03:22:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static void		ft_header(unsigned char *header, int H, int W)
{
	int		filesize;

	filesize = 54 + 4 * W * H;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = filesize;
	header[3] = filesize >> 8;
	header[4] = filesize >> 16;
	header[5] = filesize >> 24;
	header[6] = 0;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0;
	header[10] = 54;
	header[11] = 0;
	header[12] = 0;
	header[13] = 0;
}

static void		ft_bmpfileinfo(unsigned char *bmpfileinfo, int H, int W)
{
	bmpfileinfo[0] = 40;
	bmpfileinfo[1] = 0;
	bmpfileinfo[2] = 0;
	bmpfileinfo[3] = 0;
	bmpfileinfo[4] = W;
	bmpfileinfo[5] = W >> 8;
	bmpfileinfo[6] = W >> 16;
	bmpfileinfo[7] = W >> 24;
	bmpfileinfo[8] = H;
	bmpfileinfo[9] = H >> 8;
	bmpfileinfo[10] = H >> 16;
	bmpfileinfo[11] = H >> 24;
	bmpfileinfo[12] = 0;
	bmpfileinfo[13] = 0;
	bmpfileinfo[14] = 32;
	bmpfileinfo[15] = 0;
}

static void		ft_write_data(t_pixel** pixels, int H, int W, int fd)
{
	unsigned int			row;
	unsigned int			pixelBytesPerRow;
	unsigned int			paddingBytesPerRow;
	static unsigned char	zeroes[3];

	row = 0;
	pixelBytesPerRow = W * sizeof(t_pixel);
	paddingBytesPerRow = (4 - (pixelBytesPerRow % 4)) % 4;
	zeroes = {0, 0, 0};
	while (row < H)
	{
		write(fd, pixels[row], pixelBytesPerRow);
		write(fd, zeroes, paddingBytesPerRow);
		row++;
	}
}

int				ft_save_bmp(unsigned int *data, int H, int W)
{
	int				fd;
	unsigned char	header[14];
	unsigned char	bmpfileinfo[40];

	if ((fd = open("minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		return(ft_error("Failed to save image as miniRT.bmp", 0));
	ft_memset(header, 0, 14);
	ft_memset(bmpfileinfo, 0, 40);
	ft_header(header, W, H);
	ft_bmpfileinfo(bmpfileinfo, W, H);
	write(fd, header, 14);
	write(fd, bmpfileinfo, 40);
	ft_write_data(pixels, W, H, fd);
	close(fd);
	return (0);
}
