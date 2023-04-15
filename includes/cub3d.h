#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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

//parsing
int			parsing(int argc, char **argv, t_info **info);
char		**map_to_matrix(int fd, int len);
int			divide_gen_map(char **gen_map, t_info **info);
int			color_to_info(char **color_map, t_info **info, char c);
int			ft_colors(char **gen_map, int i, t_info **info, int *count);
int			ft_texture(char **gen_map, int i, t_info **info);
int			check_zero(char **gen_map);
int			texture_to_info(char *str, t_info **info, int flag);
void		separate_map(t_info **info, char **gen_map, int index, int i);
//libft
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
int			matrix_len(char **str);
void		matrix_free(char **str);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
char		*ft_substr(char *s, int start, int len);
int			ft_strlcpy(char *dst, char *src, int destsize);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);

#endif