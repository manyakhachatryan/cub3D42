/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <manykhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:09:44 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:22:17 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define BUFFER_SIZE  1

typedef struct s_info
{
	char	**map;

	char	**colors_f;
	int		flag_c_f;
	char	**colors_c;
	int		flag_c_c;

	char	*texture_no;
	int		flag_tex_no;
	char	*texture_so;
	int		flag_tex_so;
	char	*texture_we;
	int		flag_tex_we;
	char	*texture_ea;
	int		flag_tex_ea;

	char	**game_map;
}			t_info;

# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

typedef struct s_cub
{
	char	**map;
	char	**texture;
}				t_cub;

typedef struct s_elements
{
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	int		_f[3];
	int		_c[3];
}				t_elements;

typedef struct s_data
{
	int		pos_x;
	int		pos_y;
	char	**map;
	int		x;
	int		y;
}				t_data;

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_game
{
	int		f_color;
	int		c_color;
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_addres
{
	t_raycasting	*rcasting;
	t_elements		elements;
	t_index			*index;
	t_game			*game;
	t_data			data;
	t_img			*img;
	t_cub			cub;
}				t_addres;

//parsing
int			count_map_len(char *argv);
int			check_zero(char **gen_map);
char		**map_to_matrix(int fd, int len);
int			parsing(int argc, char **argv, t_info **info);
int			divide_gen_map(char **gen_map, t_info **info);
int			dublicte_symbol(char **g_map, int i, int index);
int			check_valid_map(char **g_map, int i, int index);
int			ft_texture(char **gen_map, int i, t_info **info);
int			texture_to_info(char *str, t_info **info, int flag);
int			color_to_info(char **color_map, t_info **info, char c);
int			ft_colors(char **gen_map, int i, t_info **info, int *count);
void		separate_map(t_info **info, char **gen_map, int index, int i);

//libft
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
int			matrix_len(char **str);
char		*get_next_line(int fd);
void		matrix_free(char **str);
long long	ft_atoi(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char *s, int start, int len);
char		*ft_substr(char *s, int start, int len);
int			ft_strlcpy(char *dst, char *src, int destsize);

//raycasting
char		*read_map(int fd);
float		ft_abs(float num);
int			checker(t_cub cub);
void		free_cub(t_cub cub);
void		free_mtx(char **mtx);
int			find_char(char *str);
char		*join_mtx(char **mtx);
int			tab_count(char	*str);
void		clean_tabs(char **map);
char		*reset_tabs(char *str);
char		**getmap(char *filename);
t_data		data_collector(t_cub cub);
void		move_up(t_addres *address);
int			find_map_symbol(char *str);
char		*get_correct_arg(char *ptr);
void		free_all(t_addres *address);
void		init_win(t_addres *address);
void		move_left(t_addres *address);
void		move_down(t_addres *address);
int			check_args(int ac, char **av);
void		move_right(t_addres *address);
int			close_game(t_addres *address);
int			check_texture(char **texture);
int			check_nwse(t_addres *address);
void		initializer(t_addres *address);
void		init_structs(t_addres *address);
int			check_texture_symbols(char *str);
void		norm_init_win(t_addres *address);
char		*open_tabs(char *str, int count);
int			ft_texx(t_addres *address, int n);
void		free_elements(t_elements elements);
int			check_texture_args(char **texture);
void		norm_init_win_3(t_addres *address);
void		find_pos_player(t_addres *address);
void		norm_init_win_2(t_addres *address);
void		ft_get_data_addr(t_addres *address);
void		getter_cub(t_data *data, t_cub cub);
void		init_struct_game(t_addres *address);
void		init_struct_index(t_addres *address);
void		continue_init_win(t_addres *address);
int			map_collector(t_cub *cub, char **mtx);
void		parser(t_addres *addres, char ***map);
int			key_manager(int key, t_addres *address);
int			struct_collector(t_cub *cub, char **mtx);
int			texture_collector(t_cub *cub, char **mtx);
void		init_struct_raycasting(t_addres *address);
int			color_checker(t_elements *elements, char *str);
void		rotate_right(t_addres *address, double rotate);
void		init_dir(t_addres *address, double i, double j);
void		init_player_pos(t_addres *address, int i, int j);
void		init_plane(t_addres *address, double i, double j);
void		getter_elements(t_data *data, t_elements elements);
int			elements_collector(t_elements *elements, char **texture);
int			color_collector(t_elements *elements, char **sp, int flag);
int			draw_walls(t_addres *address, char *dest, char *dest_2, int texx);
#endif
