/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:26:08 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/20 08:33:19 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef __CUB3D_H
#	define __CUB3D_H
#	include <math.h>
#	include <stdio.h>
#	include "../gnl/get_next_line.h"
#	include "../../libft/libft.h"
#	include "../minilibx/mlx.h"

typedef	enum				e_error
{
	ERROR,
	ZBUFFER_ERROR,
	NB_ARG_ERROR,
	NB_ARG_ERROR_TOO_FEW,
	NB_ARG_ERROR_TOO_MANY,
	FILE_EXT_ERROR,
	SAVE_FLAG_ERROR,
	FILE_READ_ERROR,
	SCREEN_ERROR,
	ARGUMENT_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
	RGB_ERROR,
	OPEN_ERROR,
	WRITE_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	MALLOC_ERROR,
	IMG_ERROR,
	IMG_ERROR_WEAPON_1,
	IMG_ERROR_WEAPON_2,
	IMG_ERROR_WEAPON_3,
	IMG_ERROR_WEAPON_4,
	IMG_ERROR_WEAPON_5,
	IMG_ERROR_ITEM,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR_SP,
	TEX_ERROR_SP1,
	TEX_ERROR_D,
	TEX_ERROR_B,
	TEX_ERROR_A,
	TEX_ERROR_T,
	TEX_ERROR_E1,
	TEX_ERROR_E2,
	TEX_ERROR_E3,
	TEX_ERROR_E4,
	TEX_ERROR_E5,
	TEX_ERROR_E6,
	TEX_ERROR_E7,
	TEX_ERROR_E8,
	TEX_ERROR_E9,
	TEX_ERROR_ENNEMY,
	MLX_ERROR,
	TEX_ERROR,
	PIXEL_ERROR,
	COLOR_ERROR,
	SUCCESS
}							t_error;

typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct				s_map
{
	char					*line;
	struct s_map			*next;
}							t_map;

typedef struct				s_save
{
	int						height;
	int						width;
	int						pad;
	unsigned char			*file_header;
	unsigned char			*img_header;
	int						fd;
}							t_save;

typedef struct				s_arg
{
	int						screen_w;
	int						screen_h;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*sprite;
	char					*sprite1;
	char					*door;
	char					*bonus;
	char					*ammo;
	char					*ennemy;
	char					*treasure;
	t_rgb					floor;
	t_rgb					ceil;
	t_map					*map;
}							t_arg;

typedef	struct				s_tex
{
	void					*tex_ptr;
	int						*tex_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	char					*type;
	int						sprite_x;
	int						sprite_y;
}							t_tex;

typedef	struct				s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_img;

typedef struct				s_sprite_data
{
	double					sp_dist;
	double					spcamx;
	double					spcamy;
	double					transx;
	double					transy;
	int						spritescreenx;
	int						sprite_height;
	int						drawstart_y;
	int						drawend_y;
	int						sprite_width;
	int						drawstart_x;
	int						drawend_x;
	int						stripe;
	int						sp_x;
	int						sp_y;
}							t_sprite_data;

typedef struct				s_move
{
	int						up;
	int						down;
	int						left;
	int						right;
	int						strafl;
	int						strafr;
	int						lean_for;
	int						lean_back;
	int						jump_crouch;
	int						collision;
}							t_move;

typedef struct				s_ray
{
	double					planex;
	double					planey;
	double					stepx;
	double					stepy;
	double					dirx;
	double					diry;
	int						tex_x;
	int						tex_y;
	double					rposx;
	double					rposy;
	double					rdirx;
	double					rdiry;
	double					rdisdx;
	double					rdisdy;
	double					rdistx;
	double					rdisty;
	int						rmapx;
	int						rmapy;
	int						wall;
	int						wstart;
	int						wend;
	double					camera;
	int						hit;
	double					rh;
	double					step_tex;
	double					tex_pos;
	double					dist;
	double					speed;
	double					*zbuffer;
	int						*sp_order;
	double					*sp_distance;\
	int						sprite;
	int						sprite_x;
	int						sprite_y;
	double					sprite_dist;
	double					spstart;
	double					spend;
	int						ennemy;
	int						door;
}							t_ray;

typedef struct				s_weapon
{
	char					*name;
	int						ammo;
	int						height;
	int						width;
	char					*path;
	int						color;
	char					*bullet_path;
	t_img					*img;
}							t_weapon;

typedef struct				s_weapon_list
{
	t_weapon				weapon1;
	t_weapon				weapon2;
	t_weapon				weapon3;
	t_weapon				weapon4;
}							t_weapon_list;

typedef	struct				s_sprite
{
	double					pos_x;
	double					pos_y;
	t_tex					*tex;
}							t_sprite;

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

typedef	struct				s_env
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_arg					arg;
	char					**map;
	int						map_height;
	int						map_width;
	double					player_x;
	double					player_y;
	char					orientation;
	int						height;
	int						width;
	unsigned int			floor;
	unsigned int			ceil;
	int						error;
	t_move					move;
	t_ray					ray;
	t_img					*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	t_tex					*tex_sprite;
	t_tex					*tex_sprite1;
	t_tex					*tex_door;
	t_tex					*tex_bonus;
	t_tex					*tex_ennemy;
	t_tex					*tex_ennemy_1;
	t_tex					*tex_ennemy_2;
	t_tex					*tex_ennemy_3;
	t_tex					*tex_ennemy_4;
	t_tex					*tex_ennemy_5;
	t_tex					*tex_ennemy_6;
	t_tex					*tex_ennemy_7;
	t_tex					*tex_ennemy_8;
	t_tex					*tex_ennemy_9;
	t_tex					*tex_ammo;
	t_tex					*tex_treasure;
	t_tex					*tex_floor;
	t_img					*sound_icon;
	t_img					*bullet;
	t_img					*lives_icon;
	t_img					*target;
	t_img					*weapon_img;
	int						weapon_shot;
	int						save_flag;
	int						sprite_width;
	t_weapon_list			weapon_list;
	t_weapon				*current_weapon;
	int						weapon_id;
	unsigned int			color;
	double					lives;
	t_sprite				*sprite_tex;
	int						sound;
	int						minimap;
	int						sprite_count;
	t_sprite				*sprite_tab;
	t_sprite_data			sprite;
	int						open_door;
	int						shot_box_x;
	int						shot_box_y;
	int						shot_box_size;
	int						ennemy_can_be_shot;
	int						ennemy_be_shot_x;
	int						ennemy_be_shot_y;
	int						ennemy_count;
	int						level;
	int						treasure_caught;
	int						count_ennemy_gif;
	double					target_divider;
}							t_env;

/*
**	parser.c
*/
int							fetch_arguments(t_arg *arg, char *buff);

/*
** parser_tex.c
*/

int							check_path(t_arg *arg, char *buff);
int							check_path1(char *orientation, char \
		*buff, int i, t_arg *arg);
int							check_path2(char *orientation, char \
		*buff, int i, t_arg *arg);
int							check_path3(char *orientation, char \
		*buff, int i, t_arg *arg);

/*
** map.c
*/
int							check_map(t_map *map, int count_pos, int i);
/*
** init.c
*/
t_tex						*ft_new_tex(t_env *env, char *file, char *type);
int							init_items(t_env *env);
t_env						init_env(t_arg arg);
t_img						*ft_new_img(t_env *env, char *file);
/*
** init2.c
*/
int							from_rgb_to_hex(t_rgb color);
void						get_arg_for_env(t_env *env, t_arg a, int y, int x);
t_img						*ft_new_img(t_env *env, char *file);
/*
** events.c
*/
int							ft_exit(t_env *env);
int							events(t_env env);
/*
** move.c
*/
void						ft_move(t_env *env);
/*
** display.c
*/
int							ft_disp_screen(t_env *env, int x);
int							ft_put_pixel(t_img *img, unsigned int\
		color, int p_x, int p_y);
/*
** display_items
*/
int							display_sound(t_env *env, t_pos offset,\
		int *numb_tab);
void						display_bullet(t_env *env, t_pos offset,\
		double divider, int *numb_tab);
int							display_life(t_env *env, t_pos offset,\
		int *num_tab);
int							display_target(t_env *env, t_pos offset,\
		int *numb_tab);
int							ft_disp_items(t_env *env);
/*
** ray.c
*/
void						ft_init_ray(t_env *env, int x);
void						ft_direction_ray(t_env *env);
char						ft_hit_ray(t_env *env, char wall_tex);
void						ft_size_ray(t_env *env);
void						ft_wall_tex(t_env *env, char tex);
void						ft_sprite_tex(t_env *env);
/*
** utils.c
*/
int							count_char(char *str, char c);
t_map						*ft_lstlast_map(t_map *lst);
t_map						*ft_lstnew_map(void *content);
char						*withdraw_char(char *str, char c);
void						ft_lstadd_back_map(t_map **alst, t_map *new);
int							ft_lstsize_map(t_map *lst);
void						ft_lstclear_map(t_map **lst);
char						**from_lst_to_tab(t_map *lst);
t_img						*ft_new_image(t_env *env, int width, int height);
void						pixel_tex(t_tex *tex, t_env *env);
char						*pix_color(t_env *env, int sprite);
void						draw_rectangle(t_env env, int width, int h,\
		int x, int y, int c);
void						open_door(t_env *env, char c, int x, int y);
double						ft_abs(double x);
/*
** save.c
*/
unsigned char				*create_file_header(t_env *env, int pad);
unsigned char				*create_img_header(int height, int width);
int							write_headers(t_save *save);
int							write_colors(t_env *env, int fd, int height,\
		int width);
int							launch_save(t_env *env);
/*
** sprite.c
*/
int							sprite_count(t_env *env);
int							ft_place_sprite(t_env *env);
int							init_sprite(t_env *env);
void						ft_order_sprite(t_env *env);
void						get_ennemy_sprite(t_env *env, int i);
void						add_sprite(t_env *env);
int							add_sprite_two(t_env *env, int i);
int							sprite_count(t_env *env);
void						ft_sprite_calc(t_env *env, int i);
void						calc_end_start(t_env *env);
/*
** minimap.c
*/
void						draw_square(t_env env, int x, int y, int color);
void						init_minimap(t_env env);
/*
** weapon.c
*/
int							display_weapon(t_env env, int action,\
		t_pos offset, int *num_tab);
int							init_weapon(t_env *env);
int							change_weapon(t_env *env);
int							weapon_shot(t_env *env);
/*
** items.c
*/
void						ft_bonus(t_env *env);
void						ft_reload_ammo(t_env *env);
void						ft_ennemy(t_env *env);
void						ft_next_level(t_env *env);
/*
** free.c
*/
void						ft_free_tex(t_env *env, t_tex *tex);
void						ft_free_img(t_env *env, t_img *img);
/*
** textures.c
*/
int							init_tex(t_env *env);
/*
** error.
*/
int							ft_error(int error, t_env *env);
int							ft_error_arg(int error);
int							ft_error_tex_inputs(int error, char *orientation);
#	define INVISI_CHAR "\t\v\r\f "
#	define KEY_UP 13
#	define KEY_RIGHT 2
#	define KEY_LEFT 0
#	define KEY_DOWN 1
#	define ROTATE_LEFT 123
#	define ROTATE_RIGHT 124
#	define CROUCH 125
#	define JUMP 126
#	define KEYPRESS 2
#	define KEYRELEASE 3
#	define KEYPRESSMASK 1
#	define KEYRELEASEMASK 10
#	define SPACE_BAR 49
#	define KEY_EXIT 53
#	define KEY_ALT 261
#	define KEY_SOUND 109
#	define KEY_MINIMAP 46
#	define KEY_DOOR 31
#	define KEY_SECRET_DOOR 35
#	define KEY_RELOAD 15
#	define STRUCTURENOTIFYMASK 10001
#	define MINIMAP_SIZE 6
#	define COLOR_MAP_WALL 0x000000
#	define COLOR_MAP_PLAYER 0xff0000
#	define COLOR_MAP_FLOOR 0xffffff
#	define COLOR_MAP_SPRITE 0x00ff00
#	define COLOR_MAP_SECRET_DOOR 0x949996
#	define COLOR_MAP_DOOR 0x632b02
#	define COLOR_MAP_BONUS 0xed68ca
#	define COLOR_MAP_AMMO 0xeda705
#	define COLOR_MAP_ENNEMY 0xa418f5
#	define COLOR_MAP_TREASURE 0xbfbd2c
#	define COMPRESSION 24
#	define BYTES_PER_PIX 3
#	define FILE_HEADER_SIZE 14
#	define IMG_HEADER_SIZE 40
#	define SCREEN_PATH "screen.bmp"
#	define RIGHTS 0644
#	define COLLISION_SOUND "./sound/collision.mp3"
#	define SCREEN_MAX_HEIGHT 1440
#	define SCREEN_MAX_WIDTH 2560
#	endif
