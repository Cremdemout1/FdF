/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:27:44 by ycantin           #+#    #+#             */
/*   Updated: 2024/10/09 13:26:14 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGHT 3000
# define WIDTH 3000
# define XK_ESCAPE 0xff1b
# define XK_A 0x0061
# define XK_B 0x0062
# define XK_C 0x0063
# define XK_D 0x0064
# define XK_E 0x0065
# define XK_F 0x0066
# define XK_G 0x0067
# define XK_H 0x0068
# define XK_I 0x0069
# define XK_J 0x006a
# define XK_K 0x006b
# define XK_L 0x006c
# define XK_M 0x006d
# define XK_N 0x006e
# define XK_O 0x006f
# define XK_P 0x0070
# define XK_Q 0x0071
# define XK_R 0x0072
# define XK_S 0x0073
# define XK_T 0x0074
# define XK_U 0x0075
# define XK_V 0x0076
# define XK_W 0x0077
# define XK_X 0x0078
# define XK_Y 0x0079
# define XK_Z 0x007a
# define XK_RETURN 0xFF0D
# define XK_KP_LEFT 0xff96
# define XK_KP_UP 0xff97
# define XK_KP_RIGHT 0xff98
# define XK_KP_DOWN 0xff99
# define XK_KP_SPACE 0xff80
# define XK_KP_TAB 0xff89
# define XK_BRACKETLEFT 0x005b
# define XK_BRACKETRIGHT 0x005d
# define BUFFER_SIZE 1
# define M_PI 3.14159265358979323846
# define Y_BASE 0xfdc93e
# define Y_ADD 0xff00ff
# define B_BASE 0x5098a0
# define B_ADD 0x000fff
# define R_BASE 0x00f0f
# define R_ADD 0x000f0

typedef struct s_line
{
	float		x;
	float		x1;
	float		y;
	float		y1;
	float		dx;
	float		dy;
	int			color;
}				t_line;

typedef struct s_image
{
	char		*img_pixel_ptr;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}				t_image;

typedef struct s_transform
{
	float		zoom;
	float		rotate_x;
	float		rotate_y;
	float		rotate_z;
	int			offset_x;
	int			offset_y;
}				t_transform;

typedef struct s_bresenham
{
	int			modified_dx;
	int			modified_dy;
	int			mv_dir_x;
	int			mv_dir_y;
	int			dtrmd;
	int			holder;
}				t_bresenham;

typedef struct s_palette
{
	int			base;
	int			add_on;
}				t_palette;

typedef struct s_fdf
{
	int			key;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			height;
	int			width;
	int			**z_matrix;
	int			lod_level;
	// int             **colors;
	float		angle;
	t_palette	theme;
	t_transform	morph;
	t_line		line;
	t_bresenham	b;
	t_image		image;
}				t_fdf;

// helpers:
int				ft_atoi_basesixteen(char *str);
int				ft_count_words(const char *str, char c);
int				arg_validity(char *argv);
void			free_str_array(char **array);
int				ft_strcmp(char *s1, char *s2);
char			*static_fix(char *line);
char			*read_file(int fd, char *buffer, char *held);
char			*get_next_line(int fd);
// window:
void			free_coord(t_fdf *data);
void			destroy(t_fdf *data);
int				hook(int key, t_fdf *data);
void			initiate_structure(t_fdf *data);
// drawing:
void			read_map(t_fdf *data, char *filename);
int				mod(int diff);
int				compare(int c, int c1);
void			give_bresenham(t_fdf *data);
void			my_bresenham(t_fdf *data);
// void    dda(t_fdf *data);
void			grid(t_fdf *data);
void			draw_vertical(t_fdf *data);
void			draw_horizontal(t_fdf *data);
void			image_pixel_placement(t_fdf *data, int x, int y, int color);
// struct handling:
void			img_placeholder(t_fdf *data);
void			give_breseham(t_fdf *data);
void			transform(t_fdf *data, int *x, int *y);
// morph:
void			isometric(t_fdf *data, int *x, int *y, int z);
void			rotate_x(t_fdf *data, int *x, int *y, int *z);
void			rotate_y(t_fdf *data, int *x, int *y, int *z);
void			rotate_z(t_fdf *data, int *x, int *y, int *z);

void			translate(int key, t_fdf *data);
void			zoom(int key, t_fdf *data);
void			rotate(int key, t_fdf *data);
void			reset(t_fdf *data);
void			write_menu(t_fdf *data);
void			themes(t_fdf *data, int key);
void			independent(t_fdf *data, int key);

#endif

/*

register {
	name : blbalbab
	email: daanmlab@gmail.com
	password : yohanisalittlefrenchwhore
}

database {
	name,
	email,
	password: crypto.sha256    int max;(newUser.password)
}

----------------------------------

login {
	email: daanmlab@gmai.com
	password: yohanisalittlefrenchwhore
}

user: database.get({email: email})

if (user && user.password != crypo.sha256(login.password))
	return (403);

user.set({token: {"idktoken2138731489", validTill: 19:57}})

return (user);

------------------------------------------------------

getStuff{
	token: user.token
}

user: database.get({token});

if (page.uid != user.uid)
	return (403);


*/