/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epilar <epilar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:08:40 by epilar            #+#    #+#             */
/*   Updated: 2021/03/10 12:17:50 by epilar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define BAD_CONF 0
# define BAD_MALLOC 1
# define BAD_FD 2
# define NO_MAP_FILE 3
# define BAD_COMMAND 4
# define BAD_ARGS 5
# define NO_BMP 6
# define BAD_WIN 7
# define BAD_IMG 8
# define BAD_TEX 9
# define SCALE 8

typedef struct	s_struct
{
	char		**map;
	int			maph;
	int			mapw;
	int			x_win;
	int			y_win;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*s_tex;
	int			fl_c;
	int			ceil_c;
}				t_struct;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			en;
}				t_win;

typedef struct	s_sprt
{
	int			i;
	int			j;
	float		sx;
	float		sy;
	float		dist;
}				t_sprt;

typedef struct	s_txtrs
{
	void		*no_img;
	int			noimgw;
	int			noimgh;
	char		*no_addr;
	int			no_bpp;
	int			no_ll;
	int			no_en;
	void		*so_img;
	int			soimgw;
	int			soimgh;
	char		*so_addr;
	int			so_bpp;
	int			so_ll;
	int			so_en;
	void		*we_img;
	int			weimgw;
	int			weimgh;
	char		*we_addr;
	int			we_bpp;
	int			we_ll;
	int			we_en;
	void		*ea_img;
	int			eaimgw;
	int			eaimgh;
	char		*ea_addr;
	int			ea_bpp;
	int			ea_ll;
	int			ea_en;
	void		*s_img;
	int			simgw;
	int			simgh;
	char		*s_addr;
	int			s_bpp;
	int			s_ll;
	int			s_en;
	int			fl;
	float		hitx;
	float		hity;
	float		*zbuf;
	int			count;
	t_sprt		*sprts;
}				t_txtrs;

typedef struct	s_plr
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_key
{
	int			mvf;
	int			mvb;
	int			mvr;
	int			mvl;
	int			tnr;
	int			tnl;
}				t_key;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	t_struct	*conf;
	t_txtrs		*txtrs;
	t_key		mvfl;
}				t_all;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_flags
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
}				t_flags;

void			parser(char *arg, t_struct *conf);
char			*read_cub(char *argv);
char			*strjoinfree(char *str, char *buf);
void			get_r_param(char *p, t_struct *conf);
char			*get_txtr_param(char *p);
int				get_col_param(char *p);
void			get_map(t_struct *conf, char *str);
int				count_param(char *p);
void			fill_map(t_struct *conf, char *p, int lines, int maxl);
int				count_lines(char *p);
int				get_max_length(char *p, int lines);
int				strlen_n(char *p);
void			check_col_param(char *p);
void			check_txtr_junk_b(char *p);
void			check_txtr_junk_e(char *p);
void			check_conf(t_struct *conf);
void			check_links(t_struct *conf);
void			check_openzeros(t_struct *conf);
void			check_plrsprpos(t_struct *conf);
void			check_validsym(t_struct *conf);
void			check_playernum(t_struct *conf);
void			check_isparam_copy(char *str);
void			check_junk(char *str);
int				check_ident(char *str, int i);
int				check_ident2(char *str, int i);
void			check_map_link(char *arg);
void			check_screen(t_all *all, t_win *win);
void			callerror(char error_code);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
void			draw_rect(t_win *win, int x, int y, int color);
void			draw_map(t_all *all);
void			draw_player(t_all *all);
void			init_player(t_all *all);
void			init_plr_dir(t_all *all, char c);
void			draw_rays(t_all *all);
void			draw_updown(t_all *all);
void			draw_vline(t_all *all, float dwall, int imgcol);
void			draw_walls(t_all *all);
float			get_wall_hit(t_all *all, t_plr *ray);
void			get_txtr_flag(t_all *all, t_plr ray);
unsigned int	get_txtr_color(t_all *all, float dwall, int row);
unsigned int	get_txtr_color1(t_all *all, int row, float q);
unsigned int	get_txtr_color2(t_all *all, int row, float q);
unsigned int	get_txtr_color3(t_all *all, int row, float q);
unsigned int	get_txtr_color4(t_all *all, int row, float q);
void			zero_txtrs_params(t_txtrs *txtrs);
void			draw_sprites(t_all *all);
int				count_sprites(t_all *all);
void			init_sprts_array(t_all *all);
void			fill_sprts_array(t_all *all);
void			sort_sprts_array(t_all *all);
void			analyze_sprts(t_all *all);
void			place_sprts(t_all *all, int n, float ang);
void			sprite2image(t_all *all, int n, int wincol);
int				get_sprite_color(t_all *all, int row, int col, int l);
void			draw_sprite_square(t_all *all, int n, int scol, int l);
void			init_sprt_txtr(t_all *all, t_txtrs *txtrs);
void			enter_sprt_params(t_all *all, int n, int i, int j);
int				key_move(t_all *all);
void			move_forward(t_all *all);
void			move_backward(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);
int				set_mvfl(int key, t_all *all);
int				unset_mvfl(int key, t_all *all);
void			init_txtrs(t_all *all, t_txtrs *txtrs);
void			image2bmp(t_all *all);
void			write_bmpfh(t_all *all, int fd);
void			write_bmpih(t_all *all, int fd);
int				main(int argc, char **argv);
void			play(t_all *all, char *arg);
void			get_screenshot(t_all *all, char *arg);
void			init_structs(t_all *all, char *arg);
void			init_conf(t_all *all, char *arg);
void			init_mlx(t_all *all);
int				quit(void);

#endif
