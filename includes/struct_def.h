/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:43:00 by adelille          #+#    #+#             */
/*   Updated: 2021/01/30 16:13:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# define CAM 0
# define LIGHT 1
# define SPHERE 2
# define PLANE 3
# define SQUARE 4
# define CYLINDER 5
# define TRIANGLE 6

typedef struct		s_img
{
	void			*addr;
	char			*buffer;
	int				bpp;
	int				line_size;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				size_x;
	int				size_y;
	t_img			*img;
}					t_env;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;
t_ray				ft_fill_ray(double x, double y,
							double z, t_vector direction);

typedef struct		s_inter
{
	double			t;
	double			t1;
	double			t2;
	t_vector		coord;
	t_vector		normal;
	int				hit;
	int				color;
	double			pixel_intensity;
	int				id;
	int				type;
	t_ray			ray;
}					t_inter;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
	int				shadow;
}					t_color;

typedef struct		s_matrix
{
	t_vector		right;
	t_vector		up;
	t_vector		foward;
}					t_matrix;

typedef	struct		s_camera
{
	t_vector		pos;
	t_vector		rot;
	double			fov;
	int				id;
	t_matrix		rotation_matrix;
}					t_camera;

typedef	struct		s_camera_list
{
	t_vector		*pos;
	t_vector		*rot;
	double			*fov;
	int				*id;
}					t_camera_list;

typedef struct		s_light
{
	t_vector		pos;
	t_vector		rot;
	double			ratio;
	int				colors;
	int				id;
}					t_light;

typedef struct		s_light_list
{
	t_vector		*pos;
	t_vector		*rot;
	double			*ratio;
	int				*colors;
	int				*id;
}					t_light_list;

typedef struct		s_delta
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_delta;

typedef	struct		s_obj
{
	int				id;
	int				type;
	t_vector		pos;
	t_vector		rot;
	double			diameter;
	double			H;
	int				colors;
	t_vector		points[3];
}					t_obj;

typedef	struct		s_obj_list
{
	int				*id;
	int				*type;
	t_vector		*pos;
	t_vector		*rot;
	double			*diameter;
	double			*H;
	int				*color;
	t_vector		*points[3];
}					t_obj_list;

typedef	struct		s_nb_obj
{
	size_t			cameras;
	size_t			lights;
	size_t			spheres;
	size_t			cylinders;
	size_t			planes;
	size_t			triangles;
	size_t			squares;
}					t_nb_obj;

typedef struct		s_scene
{
	int				x;
	int				y;
	t_camera_list	cameras;
	t_light_list	lights;
	t_obj_list		spheres;
	t_obj_list		planes;
	t_obj_list		triangles;
	t_obj_list		squares;
	t_obj_list		cylinders;
	t_nb_obj		nb_of;
	double			aspect_ratio;
	double			ambient_light_ratio;
	int				ambient_light_rgb;
}					t_scene;
void				ft_init_scene(t_scene *scene);

typedef struct		s_params
{
	int				i;
	t_env			*env;
	int				nb_cam;
	t_scene			*scene;
}					t_params;

typedef struct		s_pack
{
	t_vector		pos;
	t_vector		rot;
	double			diameter;
	double			H;
}					t_pack;

typedef struct		s_phong
{
	double			diffuse;
	double			specular;
}					t_phong;

typedef struct		s_header
{
	char			bmp_letters[2];
	unsigned int	file_size;
	unsigned int	reserved_bytes;
	unsigned int	buffer_offset;
}					t_header;

typedef struct		s_info
{
	unsigned int	info_size;
	int				W;
	int				H;
	unsigned short	color_planes;
	unsigned short	color_depth;
	unsigned int	compression_method;
	unsigned int	raw_data_size;
	int				horizontal_res;
	int				vertical_res;
	unsigned int	color_table_entries;
	unsigned int	important_colors;
}					t_info;

#endif
