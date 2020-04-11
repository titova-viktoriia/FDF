/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:32:13 by hdeckard          #+#    #+#             */
/*   Updated: 2020/02/18 16:55:06 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <OpenGl/gl.h>
# define WINDOW_X 1300
# define WINDOW_Y 1300
# define MENU 150
# define RAD 0.46373398
# define LEFT_BUTTON_MOUSE 1
# define RIGHT_BUTTON_MOUSE 2
# define A_BUTTON 0
# define S_BUTTON 1
# define D_BUTTON 2
# define Z_BUTTON 6
# define X_BUTTON 7
# define C_BUTTON 8
# define Q_BUTTON 12
# define W_BUTTON 13
# define E_BUTTON 14
# define PLUS_BUTTON 24
# define MINUS_BUTTON 27
# define O_BUTTON 31
# define P_BUTTON 35
# define ENTER_BUTTON 36
# define L_BUTTON 37
# define K_BUTTON 40
# define LESS_BUTTON 43
# define GREATER_BUTTON 47
# define TAB_BUTTON 48
# define SPACE_BUTTON 49
# define DELETE_BUTTON 51
# define ESC_EXIT 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ARROW_TO_DOWN 125
# define UP_ARROW 126
# define SHIFT_LEFT 257
# define SHIFT_BUTTON 258
# define COMMAND_BUTTON 259
# define CTRL_BUTTON 269
# define BACKGRAUND_0 0
# define BACKGRAUND_1 16777215
# define BACKGRAUND_2 15792383
# define BACKGRAUND_3 6266528
# define BACKGRAUND_4 11393254
# define COLOR_1 12399524
# define COLOR_2 16777200

typedef struct	s_point
{
	int		z;
	int		color;
	int		store;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*image_menu;
	void		*image_mode_menu;
	void		*image_col_menu;
	int			*data_img;
	int			*data_img_menu;
	int			*data_img_mode_menu;
	int			*data_img_col_menu;
	char		*argv;
	int			bpp;
	int			size_line;
	int			endian;
	int			projection;
	int			height_p;
	int			width_p;
	int			step;
	int			first_y;
	int			first_x;
	int			fix_y;
	int			fix_x;
	int			deltax;
	int			deltay;
	int			dirx;
	int			diry;
	int			max_z;
	int			min_z;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			colors[5];
	int			backgraund;
	int			backgraund_color;
	int			type_of_coloration;
	int			center_x;
	int			center_y;
	double		rad_p;
	double		rad_p_2;
	double		rad_p_3;
	double		mn;
	double		mn_x;
	double		mn_y;
	int			switcher;
	int			mouse;
	int			mouse_mode;
	int			mouse_color_1;
	int			mouse_color_2;
	int			brush;
	int			type_of_brush;
	t_point		***karta;
	void		*image_2;
	int			*data_img_2;
}				t_fdf;

void			initialization(t_fdf *fdf, char *argv);
void			required_values(t_fdf *fdf, int fw, int fh);
int				get_color(int p, int r, int g, int b);
void			line_drawing(t_fdf *fdf, int x, int y);
void			get_ab(t_fdf *fdf, int x, int y, int i);
int				color(int c1, int c2, int delta, int now);
void			line(t_fdf *fdf, int c1, int c2);
void			program_control(t_fdf *fdf);
void			image_creation(t_fdf *fdf);
void			backgraund(t_fdf *fdf);
int				read_check(char *argv, t_fdf *fdf);
int				ft_w_count(char const *s, char c);
int				ft_new_t_p(t_fdf *fdf);
int				fill_t_p_karta(char *argv, t_fdf *fdf);
int				ft_atoi_16_10(const char *str);
void			get_first_point(t_fdf *fdf);
void			clean_up(t_fdf *fdf);
void			x_rotate(int *y, int *z, double angle);
void			y_rotate(int *x, int *z, double angle);
void			z_rotate(int *x, int *y, double angle);
void			iso_projection(int *x, int *y, int z);
void			set_color_z(t_fdf *fdf);
void			set_color_g(t_fdf *fdf);
void			set_color_mouse(t_fdf *fdf, int c1, int c2);
void			return_true_color(t_point ***karta, int w, int h);
void			save_color(t_point ***karta, int w, int h);
void			last_point(t_fdf *fdf);
void			key_press_2(int button, t_fdf *fdf);
void			key_press_3(int button, t_fdf *fdf);
void			key_press_4(int button, t_fdf *fdf);
void			key_press_5(int button, t_fdf *fdf);
void			key_press_6(int button, t_fdf *fdf);
void			key_press_7(int button, t_fdf *fdf);
void			palitra(t_fdf *fdf, int x, int y);
void			picture(t_fdf *fdf);
void			mouse_press_palitra(int button, int x, int y, t_fdf *fdf);
void			mouse_press_background(int button, int x, int y, t_fdf *fdf);
void			mouse_move_palitra(int x, int y, t_fdf *fdf);
void			mouse_nopress_palitra(int x, int y, t_fdf *fdf);
int				fill_or_not_to_fill(t_fdf *fdf, int x, int y, int i);
void			menu_1(t_fdf *fdf);
void			mouse_press_center(int button, int x, int y, t_fdf *fdf);
void			mouse_press_rotate(int button, int x, int y, t_fdf *fdf);
void			mouse_press_mode(int button, int x, int y, t_fdf *fdf);
void			mouse_move_center(int x, int y, t_fdf *fdf);
void			mouse_move_rotate(int x, int y, t_fdf *fdf);
void			mouse_scroll(int button, t_fdf *fdf);
void			fdf_rad_return(t_fdf *fdf);
void			mouse_press_color(int button, int x, int y, t_fdf *fdf);
void			initial_setup(t_fdf *fdf);
void			image_menu(t_fdf *fdf);
void			remove_map(t_point ****karta, int x1, int y1);

#endif
